/*
 * Copyright (c) 2018, Technische Universität Kaiserslautern
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors:
 *    Johannes Feldmann
 *    Lukas Steiner
 *    Luiza Correa
 *    Derek Christ
 */

#include <cmath>
#include <iostream>
#include <iomanip>
#include <bitset>

#include "AddressDecoder.h"
#include "../common/utils.h"
#include "../configuration/Configuration.h"

AddressDecoder::AddressDecoder(const Configuration& config, const DRAMSysConfiguration::AddressMapping &addressMapping)
{
    if (const auto &channelBits = addressMapping.channelBits)
    {
        std::copy(channelBits->begin(), channelBits->end(), std::back_inserter(vChannelBits));
    }

    if (const auto &rankBits = addressMapping.rankBits)
    {
        std::copy(rankBits->begin(), rankBits->end(), std::back_inserter(vRankBits));
    }

    if (const auto &bankGroupBits = addressMapping.bankGroupBits)
    {
        std::copy(bankGroupBits->begin(), bankGroupBits->end(), std::back_inserter(vBankGroupBits));
    }

    if (const auto &byteBits = addressMapping.byteBits)
    {
        std::copy(byteBits->begin(), byteBits->end(), std::back_inserter(vByteBits));
    }

    if (const auto &xorBits = addressMapping.xorBits)
    {
        for (const auto &xorBit : *xorBits)
        {
            vXor.emplace_back(xorBit.first, xorBit.second);
        }
    }

    if (const auto &bankBits = addressMapping.bankBits)
    {
        std::copy(bankBits->begin(), bankBits->end(), std::back_inserter(vBankBits));
    }

    if (const auto &rowBits = addressMapping.rowBits)
    {
        std::copy(rowBits->begin(), rowBits->end(), std::back_inserter(vRowBits));
    }

    if (const auto &columnBits = addressMapping.columnBits)
    {
        std::copy(columnBits->begin(), columnBits->end(), std::back_inserter(vColumnBits));
    }

    unsigned channels = std::lround(std::pow(2.0, vChannelBits.size()));
    unsigned ranks = std::lround(std::pow(2.0, vRankBits.size()));
    unsigned bankGroups = std::lround(std::pow(2.0, vBankGroupBits.size()));
    unsigned banks = std::lround(std::pow(2.0, vBankBits.size()));
    unsigned rows = std::lround(std::pow(2.0, vRowBits.size()));
    unsigned columns = std::lround(std::pow(2.0, vColumnBits.size()));
    unsigned bytes = std::lround(std::pow(2.0, vByteBits.size()));

std::cout<<"bankGroups "<<bankGroups<<"\n";
std::cout<<"channels "<<channels<<"\n";
std::cout<<"ranks "<<ranks<<"\n";
std::cout<<"banks "<<banks<<"\n";
std::cout<<"rows "<<rows<<"\n";
std::cout<<"columns "<<columns<<"\n";
std::cout<<"bytes "<<bytes<<"\n";

    maximumAddress = static_cast<uint64_t>(bytes) * columns * rows * banks
            * bankGroups * ranks * channels - 1;

    bankgroupsPerRank = bankGroups;
    bankGroups = bankgroupsPerRank * ranks;

    banksPerGroup = banks;
    banks = banksPerGroup * bankGroups;

    const MemSpec& memSpec = *config.memSpec;

    if (memSpec.numberOfChannels != channels || memSpec.ranksPerChannel != ranks
        || memSpec.bankGroupsPerChannel != bankGroups || memSpec.banksPerChannel != banks
        || memSpec.rowsPerBank != rows || memSpec.columnsPerRow != columns
        || memSpec.devicesPerRank * memSpec.bitWidth != bytes * 8)
        SC_REPORT_FATAL("AddressDecoder", "Memspec and address mapping do not match");
    std::cout<<memSpec.numberOfChannels<<" "<<channels<<" "<<memSpec.ranksPerChannel<<" "<<ranks<<" "<<memSpec.bankGroupsPerChannel<<" "<<bankGroups<<" "<<memSpec.rowsPerBank<<" "<<rows<<" "<<memSpec.columnsPerRow<<" "<<columns<<" "<<memSpec.devicesPerRank* memSpec.bitWidth<<" "<<bytes * 8 ;

}

DecodedAddress AddressDecoder::decodeAddress(uint64_t encAddr)
{
    if (encAddr > maximumAddress)
        SC_REPORT_WARNING("AddressDecoder", ("Address " + std::to_string(encAddr) + " out of range (maximum address is " + std::to_string(maximumAddress) + ")").c_str());

    // Apply XOR
    // For each used xor:
    //   Get the first bit and second bit. Apply a bitwise xor operator and save it back to the first bit.
    for (auto &it : vXor)
    {
        uint64_t xoredBit;
        xoredBit = (((encAddr >> it.first) & UINT64_C(1)) ^ ((encAddr >> it.second) & UINT64_C(1)));
        encAddr &= ~(UINT64_C(1) << it.first);
        encAddr |= xoredBit << it.first;
    }

    DecodedAddress decAddr;

    for (unsigned it = 0; it < vChannelBits.size(); it++)
        decAddr.channel |= ((encAddr >> vChannelBits[it]) & UINT64_C(1)) << it;

    for (unsigned it = 0; it < vRankBits.size(); it++)
        decAddr.rank |= ((encAddr >> vRankBits[it]) & UINT64_C(1)) << it;

    for (unsigned it = 0; it < vBankGroupBits.size(); it++)
        decAddr.bankgroup |= ((encAddr >> vBankGroupBits[it]) & UINT64_C(1)) << it;

    for (unsigned it = 0; it < vBankBits.size(); it++)
        decAddr.bank |= ((encAddr >> vBankBits[it]) & UINT64_C(1)) << it;

    for (unsigned it = 0; it < vRowBits.size(); it++)
        decAddr.row |= ((encAddr >> vRowBits[it]) & UINT64_C(1)) << it;

    for (unsigned it = 0; it < vColumnBits.size(); it++)
        decAddr.column |= ((encAddr >> vColumnBits[it]) & UINT64_C(1)) << it;

    for (unsigned it = 0; it < vByteBits.size(); it++)
        decAddr.byte |= ((encAddr >> vByteBits[it]) & UINT64_C(1)) << it;

    decAddr.bankgroup = decAddr.bankgroup + decAddr.rank * bankgroupsPerRank;
    decAddr.bank = decAddr.bank + decAddr.bankgroup * banksPerGroup;

    return decAddr;
}

void AddressDecoder::print()
{
    std::cout << headline << std::endl;
    std::cout << "Used Address Mapping:" << std::endl;
    std::cout << std::endl;

    for (int it = static_cast<int>(vChannelBits.size() - 1); it >= 0; it--)
    {
        uint64_t addressBits = (UINT64_C(1) << vChannelBits[static_cast<std::vector<unsigned>::size_type>(it)]);
        for (auto it2 : vXor)
        {
            if (it2.first == vChannelBits[static_cast<std::vector<unsigned>::size_type>(it)])
                addressBits |= (UINT64_C(1) << it2.second);
        }
        std::cout << " Ch " << std::setw(2) << it << ": " << std::bitset<64>(addressBits) << std::endl;
    }

    for (int it = static_cast<int>(vRankBits.size() - 1); it >= 0; it--)
    {
        uint64_t addressBits = (UINT64_C(1) << vRankBits[static_cast<std::vector<unsigned>::size_type>(it)]);
        for (auto it2 : vXor)
        {
            if (it2.first == vRankBits[static_cast<std::vector<unsigned>::size_type>(it)])
                addressBits |= (UINT64_C(1) << it2.second);
        }
        std::cout << " Ra " << std::setw(2) << it << ": " << std::bitset<64>(addressBits) << std::endl;
    }

    for (int it = static_cast<int>(vBankGroupBits.size() - 1); it >= 0; it--)
    {
        uint64_t addressBits = (UINT64_C(1) << vBankGroupBits[static_cast<std::vector<unsigned>::size_type>(it)]);
        for (auto it2 : vXor)
        {
            if (it2.first == vBankGroupBits[static_cast<std::vector<unsigned>::size_type>(it)])
                addressBits |= (UINT64_C(1) << it2.second);
        }
        std::cout << " Bg " << std::setw(2) << it << ": " << std::bitset<64>(addressBits) << std::endl;
    }

    for (int it = static_cast<int>(vBankBits.size() - 1); it >= 0; it--)
    {
        uint64_t addressBits = (UINT64_C(1) << vBankBits[static_cast<std::vector<unsigned>::size_type>(it)]);
        for (auto it2 : vXor)
        {
            if (it2.first == vBankBits[static_cast<std::vector<unsigned>::size_type>(it)])
                addressBits |= (UINT64_C(1) << it2.second);
        }
        std::cout << " Ba " << std::setw(2) << it << ": " << std::bitset<64>(addressBits) << std::endl;
    }

    for (int it = static_cast<int>(vRowBits.size() - 1); it >= 0; it--)
    {
        uint64_t addressBits = (UINT64_C(1) << vRowBits[static_cast<std::vector<unsigned>::size_type>(it)]);
        for (auto it2 : vXor)
        {
            if (it2.first == vRowBits[static_cast<std::vector<unsigned>::size_type>(it)])
                addressBits |= (UINT64_C(1) << it2.second);
        }
        std::cout << " Ro " << std::setw(2) << it << ": " << std::bitset<64>(addressBits) << std::endl;
    }

    for (int it = static_cast<int>(vColumnBits.size() - 1); it >= 0; it--)
    {
        uint64_t addressBits = (UINT64_C(1) << vColumnBits[static_cast<std::vector<unsigned>::size_type>(it)]);
        for (auto it2 : vXor)
        {
            if (it2.first == vColumnBits[static_cast<std::vector<unsigned>::size_type>(it)])
                addressBits |= (UINT64_C(1) << it2.second);
        }
        std::cout << " Co " << std::setw(2) << it << ": " << std::bitset<64>(addressBits) << std::endl;
    }

    for (int it = static_cast<int>(vByteBits.size() - 1); it >= 0; it--)
    {
        uint64_t addressBits = (UINT64_C(1) << vByteBits[static_cast<std::vector<unsigned>::size_type>(it)]);
        for (auto it2 : vXor)
        {
            if (it2.first == vByteBits[static_cast<std::vector<unsigned>::size_type>(it)])
                addressBits |= (UINT64_C(1) << it2.second);
        }
        std::cout << " By " << std::setw(2) << it << ": " << std::bitset<64>(addressBits) << std::endl;
    }

    std::cout << std::endl;
}

