/*
 * Copyright (c) 2019, Technische Universität Kaiserslautern
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
 *    Lukas Steiner
 *    Derek Christ
 */

#include <iostream>

#include "../../common/utils.h"
#include "MemSpecGDDR6.h"

using namespace sc_core;
using namespace tlm;

MemSpecGDDR6::MemSpecGDDR6(const DRAMSysConfiguration::MemSpec &memSpec)
    : MemSpec(memSpec, MemoryType::GDDR6,
      memSpec.memArchitectureSpec.entries.at("nbrOfChannels"),
      1,
      memSpec.memArchitectureSpec.entries.at("nbrOfRanks"),
      memSpec.memArchitectureSpec.entries.at("nbrOfBanks"),
      memSpec.memArchitectureSpec.entries.at( "nbrOfBankGroups"),
      memSpec.memArchitectureSpec.entries.at("nbrOfBanks")
          / memSpec.memArchitectureSpec.entries.at( "nbrOfBankGroups"),
      memSpec.memArchitectureSpec.entries.at("nbrOfBanks")
          * memSpec.memArchitectureSpec.entries.at("nbrOfRanks"),
      memSpec.memArchitectureSpec.entries.at( "nbrOfBankGroups")
          * memSpec.memArchitectureSpec.entries.at("nbrOfRanks"),
      memSpec.memArchitectureSpec.entries.at("nbrOfDevices")),
      per2BankOffset(memSpec.memArchitectureSpec.entries.at("per2BankOffset")),
      tRP        (tCK * memSpec.memTimingSpec.entries.at("RP")),
      tRAS       (tCK * memSpec.memTimingSpec.entries.at("RAS")),
      tRC        (tCK * memSpec.memTimingSpec.entries.at("RC")),
      tRCDRD     (tCK * memSpec.memTimingSpec.entries.at("RCDRD")),
      tRCDWR     (tCK * memSpec.memTimingSpec.entries.at("RCDWR")),
      tRTP       (tCK * memSpec.memTimingSpec.entries.at("RTP")),
      tRRDS      (tCK * memSpec.memTimingSpec.entries.at("RRDS")),
      tRRDL      (tCK * memSpec.memTimingSpec.entries.at("RRDL")),
      tCCDS      (tCK * memSpec.memTimingSpec.entries.at("CCDS")),
      tCCDL      (tCK * memSpec.memTimingSpec.entries.at("CCDL")),
      tRL        (tCK * memSpec.memTimingSpec.entries.at("RL")),
      tWCK2CKPIN (tCK * memSpec.memTimingSpec.entries.at("WCK2CKPIN")),
      tWCK2CK    (tCK * memSpec.memTimingSpec.entries.at("WCK2CK")),
      tWCK2DQO   (tCK * memSpec.memTimingSpec.entries.at("WCK2DQO")),
      tRTW       (tCK * memSpec.memTimingSpec.entries.at("RTW")),
      tWL        (tCK * memSpec.memTimingSpec.entries.at("WL")),
      tWCK2DQI   (tCK * memSpec.memTimingSpec.entries.at("WCK2DQI")),
      tWR        (tCK * memSpec.memTimingSpec.entries.at("WR")),
      tWTRS      (tCK * memSpec.memTimingSpec.entries.at("WTRS")),
      tWTRL      (tCK * memSpec.memTimingSpec.entries.at("WTRL")),
      tPD        (tCK * memSpec.memTimingSpec.entries.at("PD")),
      tCKESR     (tCK * memSpec.memTimingSpec.entries.at("CKESR")),
      tXP        (tCK * memSpec.memTimingSpec.entries.at("XP")),
      tREFI      (tCK * memSpec.memTimingSpec.entries.at("REFI")),
      tREFIpb    (tCK * memSpec.memTimingSpec.entries.at("REFIpb")),
      tRFCab     (tCK * memSpec.memTimingSpec.entries.at("RFCab")),
      tRFCpb     (tCK * memSpec.memTimingSpec.entries.at("RFCpb")),
      tRREFD     (tCK * memSpec.memTimingSpec.entries.at("RREFD")),
      tXS        (tCK * memSpec.memTimingSpec.entries.at("XS")),
      tFAW       (tCK * memSpec.memTimingSpec.entries.at("FAW")),
      tPPD       (tCK * memSpec.memTimingSpec.entries.at("PPD")),
      tLK        (tCK * memSpec.memTimingSpec.entries.at("LK")),
      tACTPDE    (tCK * memSpec.memTimingSpec.entries.at("ACTPDE")),
      tPREPDE    (tCK * memSpec.memTimingSpec.entries.at("PREPDE")),
      tREFPDE    (tCK * memSpec.memTimingSpec.entries.at("REFPDE")),
      tRTRS      (tCK * memSpec.memTimingSpec.entries.at("RTRS"))
{
    uint64_t deviceSizeBits = static_cast<uint64_t>(banksPerRank) * rowsPerBank * columnsPerRow * bitWidth;
    uint64_t deviceSizeBytes = deviceSizeBits / 8;
    memorySizeBytes = deviceSizeBytes * ranksPerChannel * numberOfChannels;

    std::cout << headline << std::endl;
    std::cout << "Memory Configuration:" << std::endl << std::endl;
    std::cout << " Memory type:           " << "GDDR6"              << std::endl;
    std::cout << " Memory size in bytes:  " << memorySizeBytes       << std::endl;
    std::cout << " Channels:              " << numberOfChannels      << std::endl;
    std::cout << " Ranks per channel:     " << ranksPerChannel << std::endl;
    std::cout << " Bank groups per rank:  " << groupsPerRank         << std::endl;
    std::cout << " Banks per rank:        " << banksPerRank          << std::endl;
    std::cout << " Rows per bank:         " << rowsPerBank << std::endl;
    std::cout << " Columns per row:       " << columnsPerRow << std::endl;
    std::cout << " Device width in bits:  " << bitWidth              << std::endl;
    std::cout << " Device size in bits:   " << deviceSizeBits        << std::endl;
    std::cout << " Device size in bytes:  " << deviceSizeBytes       << std::endl;
    std::cout << " Devices per rank:      " << devicesPerRank << std::endl;
    std::cout << std::endl;
}

sc_time MemSpecGDDR6::getRefreshIntervalAB() const
{
    return tREFI;
}

sc_time MemSpecGDDR6::getRefreshIntervalPB() const
{
    return tREFIpb;
}

sc_time MemSpecGDDR6::getRefreshIntervalP2B() const
{
    return tREFIpb;
}

unsigned MemSpecGDDR6::getPer2BankOffset() const
{
    return per2BankOffset;
}

sc_time MemSpecGDDR6::getExecutionTime(Command command, const tlm_generic_payload &payload) const
{
    if (command == Command::PREPB || command == Command::PREAB)
        return tRP;
    else if (command == Command::ACT)
    {
        if (payload.get_command() == TLM_READ_COMMAND)
            return tRCDRD + tCK;
        else
            return tRCDWR + tCK;
    }
    else if (command == Command::RD)
        return tRL + tWCK2CKPIN + tWCK2CK + tWCK2DQO + burstDuration;
    else if (command == Command::RDA)
        return tRTP + tRP;
    else if (command == Command::WR)
        return tWL + tWCK2CKPIN + tWCK2CK + tWCK2DQI + burstDuration;
    else if (command == Command::WRA)
        return tWL + burstDuration + tWR + tRP;
    else if (command == Command::REFAB)
        return tRFCab;
    else if (command == Command::REFPB || command == Command::REFP2B)
        return tRFCpb;
    else
    {
        SC_REPORT_FATAL("getExecutionTime",
                        "command not known or command doesn't have a fixed execution time");
        return SC_ZERO_TIME;
    }
}

TimeInterval MemSpecGDDR6::getIntervalOnDataStrobe(Command command, const tlm_generic_payload &) const
{
    if (command == Command::RD || command == Command::RDA)
        return {tRL + tWCK2CKPIN + tWCK2CK + tWCK2DQO, tRL + tWCK2CKPIN + tWCK2CK + tWCK2DQO + burstDuration};
    else if (command == Command::WR || command == Command::WRA)
        return {tWL + tWCK2CKPIN + tWCK2CK + tWCK2DQI, tWL + tWCK2CKPIN + tWCK2CK + tWCK2DQI + burstDuration};
    else
    {
        SC_REPORT_FATAL("MemSpecGDDR6", "Method was called with invalid argument");
        return {};
    }
}
