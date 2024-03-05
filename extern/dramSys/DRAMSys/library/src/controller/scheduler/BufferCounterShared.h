/*
 * Copyright (c) 2020, Technische Universität Kaiserslautern
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

#ifndef BUFFERCOUNTERSHARED_H
#define BUFFERCOUNTERSHARED_H

#include <vector>

#include <tlm>
#include "BufferCounterIF.h"

class BufferCounterShared final : public BufferCounterIF
{
public:
    explicit BufferCounterShared(unsigned requestBufferSize);
    bool hasBufferSpace() const override;
    void storeRequest(const tlm::tlm_generic_payload& trans) override;
    void removeRequest(const tlm::tlm_generic_payload& trans) override;
    const std::vector<unsigned> &getBufferDepth() const override;
    unsigned getNumReadRequests() const override;
    unsigned getNumWriteRequests() const override;

private:
    const unsigned requestBufferSize;
    std::vector<unsigned> numRequests;
    unsigned numReadRequests = 0;
    unsigned numWriteRequests = 0;
};

#endif // BUFFERCOUNTERSHARED_H
