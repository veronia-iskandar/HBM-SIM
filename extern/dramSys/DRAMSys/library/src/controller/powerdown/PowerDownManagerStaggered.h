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
 * Author: Lukas Steiner
 */

#ifndef POWERDOWNMANAGERSTAGGERED_H
#define POWERDOWNMANAGERSTAGGERED_H

#include <systemc>
#include "PowerDownManagerIF.h"
#include "../../common/dramExtensions.h"
#include "../checker/CheckerIF.h"

class BankMachine;

class PowerDownManagerStaggered final : public PowerDownManagerIF
{
public:
    PowerDownManagerStaggered(std::vector<BankMachine*>& bankMachinesOnRank,
                              Rank rank, CheckerIF& checker);

    void triggerEntry() override;
    void triggerExit() override;
    void triggerInterruption() override;

    CommandTuple::Type getNextCommand() override;
    void updateState(Command) override;
    sc_core::sc_time start() override;

private:
    enum class State {Idle, ActivePdn, PrechargePdn, SelfRefresh, ExtraRefresh} state = State::Idle;
    tlm::tlm_generic_payload powerDownPayload;
    std::vector<BankMachine*>& bankMachinesOnRank;
    CheckerIF& checker;

    sc_core::sc_time timeToSchedule = sc_core::sc_max_time();
    Command nextCommand = Command::NOP;

    bool controllerIdle = true;
    bool entryTriggered = true;
    bool exitTriggered = false;
    bool enterSelfRefresh = false;
};

#endif // POWERDOWNMANAGERSTAGGERED_H
