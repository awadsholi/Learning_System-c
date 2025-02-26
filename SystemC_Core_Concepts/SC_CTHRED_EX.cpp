/*
    SC_CTHREAD USES AS SC_THREAD BUT WITH A CLOCK FOR SYNCHRONOUS EXECUTION

*/
#include <systemc.h>

SC_MODULE(CTHREAD_EXAMPLE){

    sc_in <bool> clk;

    void clocked_process(){
        while(true){
          cout << "SC_CTHREAD triggered at clock edge!!" << endl;
          wait();  //// Wait for next clock cycle 
        }

    }

    SC_CTOR(CTHREAD_EXAMPLE){
       SC_CTHREAD(clocked_process, clk.pos()); // Sensitive to clock positive edge 
    }


};



int sc_main(int argc, char* argv[]){
    sc_clock clk("clk",5,SC_NS); // 10 ns clock (new clock every 50 NS)
    CTHREAD_EXAMPLE module("Example_Cthread");

    module.clk(clk);
    sc_start(50,SC_NS);
    return 0;
}
