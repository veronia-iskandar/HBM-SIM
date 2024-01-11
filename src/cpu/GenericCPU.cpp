#include "cpu/GenericCPU.hpp"

GenericCPU::GenericCPU(sc_module_name name, unsigned bInByte,
                       unsigned freqInMHz, Terminator& t,
                       uint64_t W)
        : CPU_IF(name, bInByte, freqInMHz, t),
          WIDTH(W)
{
    //sc_module_name name_if =name;
    //data_length = bInByte;
    //if(STRIDE == 0 || BURST_LENGTH == 0 || WIDTH == 0)
    //SC_REPORT_FATAL(this->name(), "invalid arguments");
    //if(REP != 0)
    //name_if=name;

    if((strcmp(name, "CPU_0") == 0)||(strcmp(name, "CPU_1") == 0)||(strcmp(name, "CPU_2") == 0)||(strcmp(name, "CPU_3") == 0)||(strcmp(name, "CPU_4") == 0)||(strcmp(name, "CPU_5") == 0)||(strcmp(name, "CPU_6") == 0)   ||(strcmp(name, "CPU_7") == 0))
        SC_THREAD(send);
    buffer = new unsigned char[bInByte*32];
}

GenericCPU::~GenericCPU()
{
    delete[] buffer;
}

void GenericCPU::peqCallback(tlm::tlm_generic_payload& gp,
                             const tlm::tlm_phase& phase)
{

      
    if(phase == tlm::END_REQ){
        recievedEndReq.notify(SC_ZERO_TIME);
    }
    else if(phase == tlm::BEGIN_RESP){

        if(!gp.is_response_ok())
           std::cerr << name() << " response error: " <<
        	" Transaction failed; &gp = " << &gp << std::endl;
        numProcessed++;
        tlm::tlm_generic_payload& n_gp = gp;
        tlm::tlm_phase n_phase = tlm::END_RESP;
        sc_time n_delay = SC_ZERO_TIME;
        iSocket->nb_transport_fw(n_gp, n_phase, n_delay);
        gp.release();
             		cout<<name()<<" numProcessed: "<<numProcessed<<" numTransactions: "<<numTransactions<<"\n";
        if (numProcessed == numTransactions) {
                terminate();
         }

       
           
    }
    else{
        SC_REPORT_FATAL("StrideCPU", "PEQ was triggered with unknown phase");
    }
}

void GenericCPU::send()
{
    //std::ifstream file;
    std::ifstream file_r;
    std::ifstream file_w;
    add();
    if(strcmp(name(), "CPU_0") == 0){
        //add();
        file_r.open("../traces/insert_sort/ch_0-r.csv");
        file_w.open("../traces/insert_sort/ch_0-w.csv");
    }
   else if(strcmp(name(), "CPU_1") == 0){
        //add();
        file_r.open("../traces/insert_sort/ch_1-r.csv");
        file_w.open("../traces/insert_sort/ch_1-w.csv");
    }
    else if(strcmp(name(), "CPU_2") == 0){
        //add();
        file_r.open("../traces/insert_sort/ch_2-r.csv");
        file_w.open("../traces/insert_sort/ch_2-w.csv");
    }
    else if(strcmp(name(), "CPU_3") == 0){
        //add();
        file_r.open("../traces/insert_sort/ch_3-r.csv");
        file_w.open("../traces/insert_sort/ch_3-w.csv");
    }
    else if(strcmp(name(), "CPU_4") == 0){
        //add();
        file_r.open("../traces/insert_sort/ch_4-r.csv");
        file_w.open("../traces/insert_sort/ch_4-w.csv");
    }
    else if(strcmp(name(), "CPU_5") == 0){
        //add();
        file_r.open("../traces/insert_sort/ch_5-r.csv");
        file_w.open("../traces/insert_sort/ch_5-w.csv");
    }
    else if(strcmp(name(), "CPU_6") == 0){
        //add();
        file_r.open("../traces/insert_sort/ch_6-r.csv");
        file_w.open("../traces/insert_sort/ch_6-w.csv");
    }
    else if(strcmp(name(), "CPU_7") == 0){
        //add();
        file_r.open("../traces/insert_sort/ch_7-r.csv");
        file_w.open("../traces/insert_sort/ch_7-w.csv");
    }

    std::string   line;
    
    while(std::getline(file_r, line)) {
       numTransactions++;
    }
    while(std::getline(file_w, line)) {
       numTransactions++;
    }
    file_r.clear() ; // clear the failed state of the stream
    file_r.seekg(0);
    file_w.clear() ; // clear the failed state of the stream
    file_w.seekg(0);
std::cout<<"\n"<<name()<<" "<<numTransactions;
    unsigned long long helper;
    int delay;// = value>>43;
    int id;// = (value>>42) & 1;
    int length;// = (value>>34) & 0xFF;//255;
    int address;

    while(std::getline(file_r, line)) {
        std::istringstream buffer_file(line);
        buffer_file >> std::hex >> helper;
        delay = helper>>43;
        id = (helper>>42) & 1;
        length = (helper>>34) & 0xFF;//255;
        address = helper & 0x7FFFFFFFF;//34359738367;
        cout<<line<<"\n";
        //printf("Delay: %d \n ", delay);
        //printf("ID: %d \n ", id);
        //printf("Length: %d \n ", length);
        //printf("Address: %d \n ", address);

        tlm::tlm_command command = tlm::TLM_READ_COMMAND;
        tlm::tlm_generic_payload* gp = mm.allocate();
        gp->acquire();
        gp->set_command(command);
        gp->set_address(address);
        gp->set_data_ptr(buffer);
        gp->set_data_length(length);
        gp->set_streaming_width(length);
        gp->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);
        //int additionalDelay = cycle - prev_cycle;
        int additionalDelay=delay;
        sc_time delay = clk.nextPosedge(burstcnt(*gp) + additionalDelay);
        tlm::tlm_phase phase = tlm::BEGIN_REQ;
        iSocket->nb_transport_fw(*gp, phase, delay );
        wait(recievedEndReq);
    }
    while(std::getline(file_w, line)) {
        std::istringstream buffer_file(line);
        buffer_file >> std::hex >> helper;
        delay = helper>>43;
        id = (helper>>42) & 1;
        length = (helper>>34) & 0xFF;//255;
        address = helper & 0x7FFFFFFFF;//34359738367;
        cout<<line<<"\n";
        tlm::tlm_command command = tlm::TLM_WRITE_COMMAND;
        tlm::tlm_generic_payload* gp = mm.allocate();
        gp->acquire();
        gp->set_command(command);
        gp->set_address(address);
        gp->set_data_ptr(buffer);
        gp->set_data_length(length);
        gp->set_streaming_width(length);
        gp->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);
        //int additionalDelay = cycle - prev_cycle;
        int additionalDelay=delay;
        sc_time delay = clk.nextPosedge(burstcnt(*gp) + additionalDelay);
        tlm::tlm_phase phase = tlm::BEGIN_REQ;
        iSocket->nb_transport_fw(*gp, phase, delay );
        wait(recievedEndReq);
    }
    /*while(std::getline(file_r, line)) {
        std::stringstream   linestream(line);
        int                 cycle;
        uint64_t            address;
        int                 burst;
        std::string                read_write;

        while(linestream.good()) {
            std::string substr;
            getline(linestream, substr, ','); //get first string delimited by comma
            result.push_back(substr);
        }
        char * end;
        cycle = stoi(result.at(0));
        address = strtoull(result[1].c_str(), &end,10 );;
        burst = stoi(result[2]);
        read_write = result[3];
        bool sR = read_write == "r"? true:false;
        std::cout<<"\n interface " << name() <<" cycle "<<cycle<<" address "<<address<<" burst "<<burst<<" read_write "<<read_write << " gp->set_data_length "<<burst;

        tlm::tlm_command command = sR ? tlm::TLM_READ_COMMAND : tlm::TLM_WRITE_COMMAND;
        tlm::tlm_generic_payload* gp = mm.allocate();
        gp->acquire();
        gp->set_command(command);
        gp->set_address(address);
        gp->set_data_ptr(buffer);
        gp->set_data_length(burst);
        gp->set_streaming_width(burst);
        gp->set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);
        //int additionalDelay = cycle - prev_cycle;
        int additionalDelay=0;
        sc_time delay = clk.nextPosedge(burstcnt(*gp) + additionalDelay);

        tlm::tlm_phase phase = tlm::BEGIN_REQ;

        iSocket->nb_transport_fw(*gp, phase, delay );
        result.pop_back();
        result.pop_back();
        result.pop_back();
        result.pop_back();
        wait(recievedEndReq);

    }*/

}
