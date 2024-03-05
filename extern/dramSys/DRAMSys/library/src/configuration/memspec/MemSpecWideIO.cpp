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
#include "MemSpecWideIO.h"

using namespace sc_core;
using namespace tlm;

MemSpecWideIO::MemSpecWideIO(const DRAMSysConfiguration::MemSpec &memSpec)
    : MemSpec(memSpec, MemoryType::WideIO,
      memSpec.memArchitectureSpec.entries.at("nbrOfChannels"),
      1,
      memSpec.memArchitectureSpec.entries.at("nbrOfRanks"),
      memSpec.memArchitectureSpec.entries.at("nbrOfBanks"),
      1,
      memSpec.memArchitectureSpec.entries.at("nbrOfBanks"),
      memSpec.memArchitectureSpec.entries.at("nbrOfBanks")
          * memSpec.memArchitectureSpec.entries.at("nbrOfRanks"),
      memSpec.memArchitectureSpec.entries.at("nbrOfRanks"),
      memSpec.memArchitectureSpec.entries.at("nbrOfDevices")),
      tCKE    (tCK * memSpec.memTimingSpec.entries.at("CKE")),
      tCKESR  (tCK * memSpec.memTimingSpec.entries.at("CKESR")),
      tDQSCK  (tCK * memSpec.memTimingSpec.entries.at("DQSCK")),
      tAC     (tCK * memSpec.memTimingSpec.entries.at("AC")),
      tRAS    (tCK * memSpec.memTimingSpec.entries.at("RAS")),
      tRC     (tCK * memSpec.memTimingSpec.entries.at("RC")),
      tRCD    (tCK * memSpec.memTimingSpec.entries.at("RCD")),
      tRL     (tCK * memSpec.memTimingSpec.entries.at("RL")),
      tWL     (tCK * memSpec.memTimingSpec.entries.at("WL")),
      tWR     (tCK * memSpec.memTimingSpec.entries.at("WR")),
      tXP     (tCK * memSpec.memTimingSpec.entries.at("XP")),
      tXSR    (tCK * memSpec.memTimingSpec.entries.at("XSR")),
      tCCD_R  (tCK * memSpec.memTimingSpec.entries.at("CCD_R")),
      tCCD_W  (tCK * memSpec.memTimingSpec.entries.at("CCD_W")),
      tREFI   (tCK * memSpec.memTimingSpec.entries.at("REFI")),
      tRFC    (tCK * memSpec.memTimingSpec.entries.at("RFC")),
      tRP     (tCK * memSpec.memTimingSpec.entries.at("RP")),
      tRRD    (tCK * memSpec.memTimingSpec.entries.at("RRD")),
      tTAW    (tCK * memSpec.memTimingSpec.entries.at("TAW")),
      tWTR    (tCK * memSpec.memTimingSpec.entries.at("WTR")),
      tRTRS   (tCK * memSpec.memTimingSpec.entries.at("RTRS")),
      iDD0    (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd0") : 0),
      iDD2N   (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd2n") : 0),
      iDD3N   (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd3n") : 0),
      iDD4R   (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd4r") : 0),
      iDD4W   (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd4w") : 0),
      iDD5    (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd5") : 0),
      iDD6    (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd6") : 0),
      vDD     (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("vdd") : 0),
      iDD02   (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd02") : 0),
      iDD2P0  (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd2p0") : 0),
      iDD2P02 (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd2p02") : 0),
      iDD2P1  (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd2p1") : 0),
      iDD2P12 (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd2p12") : 0),
      iDD2N2  (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd2n2") : 0),
      iDD3P0  (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd3p0") : 0),
      iDD3P02 (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd3p02") : 0),
      iDD3P1  (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd3p1") : 0),
      iDD3P12 (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd3p12") : 0),
      iDD3N2  (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd3n2") : 0),
      iDD4R2  (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd4r2") : 0),
      iDD4W2  (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd4w2") : 0),
      iDD52   (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd52") : 0),
      iDD62   (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("idd62") : 0),
      vDD2    (memSpec.memPowerSpec.has_value() ? memSpec.memPowerSpec.value().entries.at("vdd2") : 0)
{
    uint64_t deviceSizeBits = static_cast<uint64_t>(banksPerRank) * rowsPerBank * columnsPerRow * bitWidth;
    uint64_t deviceSizeBytes = deviceSizeBits / 8;
    memorySizeBytes = deviceSizeBytes * ranksPerChannel * numberOfChannels;

    if (!memSpec.memPowerSpec.has_value())
        SC_REPORT_FATAL("MemSpec", "No power spec defined!");

    std::cout << headline << std::endl;
    std::cout << "Memory Configuration:" << std::endl << std::endl;
    std::cout << " Memory type:           " << "Wide I/O"            << std::endl;
    std::cout << " Memory size in bytes:  " << memorySizeBytes       << std::endl;
    std::cout << " Channels:              " << numberOfChannels      << std::endl;
    std::cout << " Ranks per channel:     " << ranksPerChannel << std::endl;
    std::cout << " Banks per rank:        " << banksPerRank          << std::endl;
    std::cout << " Rows per bank:         " << rowsPerBank << std::endl;
    std::cout << " Columns per row:       " << columnsPerRow << std::endl;
    std::cout << " Device width in bits:  " << bitWidth              << std::endl;
    std::cout << " Device size in bits:   " << deviceSizeBits        << std::endl;
    std::cout << " Device size in bytes:  " << deviceSizeBytes       << std::endl;
    std::cout << " Devices per rank:      " << devicesPerRank << std::endl;
    std::cout << std::endl;
}

sc_time MemSpecWideIO::getRefreshIntervalAB() const
{
    return tREFI;
}

// Returns the execution time for commands that have a fixed execution time
sc_time MemSpecWideIO::getExecutionTime(Command command, const tlm_generic_payload &) const
{
    if (command == Command::PREPB || command == Command::PREAB)
        return tRP;
    else if (command == Command::ACT)
        return tRCD;
    else if (command == Command::RD)
        return tRL + tAC + burstDuration;
    else if (command == Command::RDA)
        return burstDuration + tRP;
    else if (command == Command::WR)
        return tWL + burstDuration;
    else if (command == Command::WRA)
        return tWL + burstDuration - tCK + tWR + tRP;
    else if (command == Command::REFAB)
        return tRFC;
    else
    {
        SC_REPORT_FATAL("getExecutionTime",
                        "command not known or command doesn't have a fixed execution time");
        return SC_ZERO_TIME;
    }
}

TimeInterval MemSpecWideIO::getIntervalOnDataStrobe(Command command, const tlm_generic_payload &) const
{
    if (command == Command::RD || command == Command::RDA)
        return {tRL + tAC, tRL + tAC + burstDuration};
    else if (command == Command::WR || command == Command::WRA)
        return {tWL, tWL + burstDuration};
    else
    {
        SC_REPORT_FATAL("MemSpec", "Method was called with invalid argument");
        return {};
    }
}
