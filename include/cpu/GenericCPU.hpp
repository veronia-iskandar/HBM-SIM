#ifndef GENERIC_CPU_HPP
#define GENERIC_CPU_HPP

#include "cpu/CPU.hpp"

class GenericCPU : public CPU_IF{
    public:
	SC_HAS_PROCESS(GenericCPU);
	GenericCPU(sc_module_name name, unsigned bInByte, unsigned freqInMHz, Terminator& t, uint64_t W);
    	~GenericCPU();
    private:
	void send();
	void peqCallback(tlm::tlm_generic_payload& gp, const tlm::tlm_phase& phase) override;
    private:
	uint64_t  BURST_LENGTH, WIDTH ;
	bool send_READ;
	unsigned char* buffer = nullptr;
	bool eOF = false;
        unsigned data_length;
        //unsigned counter = 0;
        unsigned numProcessed = 0;
        unsigned numTransactions = 0;
        unsigned int prev_cycle = 0;
        

};
#endif /* STRIDE_CPU_HPP */
