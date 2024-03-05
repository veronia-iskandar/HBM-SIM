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

#ifndef SCHEDULERFIFO_H
#define SCHEDULERFIFO_H

#include <vector>
#include <deque>
#include <memory>

#include <tlm>
#include "SchedulerIF.h"
#include "../../common/dramExtensions.h"
#include "../BankMachine.h"
#include "BufferCounterIF.h"

class SchedulerFifo final : public SchedulerIF
{
public:
    explicit SchedulerFifo(const Configuration& config);
    bool hasBufferSpace() const override;
    void storeRequest(tlm::tlm_generic_payload&) override;
    void removeRequest(tlm::tlm_generic_payload&) override;
    tlm::tlm_generic_payload *getNextRequest(const BankMachine&) const override;
    bool hasFurtherRowHit(Bank, Row, tlm::tlm_command) const override;
    bool hasFurtherRequest(Bank, tlm::tlm_command) const override;
    const std::vector<unsigned> &getBufferDepth() const override;

private:
    std::vector<std::deque<tlm::tlm_generic_payload *>> buffer;
    std::unique_ptr<BufferCounterIF> bufferCounter;
};

#endif // SCHEDULERFIFO_H
