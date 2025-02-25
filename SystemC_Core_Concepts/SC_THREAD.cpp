

/*


            THREAD PROCESS USES FOR THE SEQUENTIAL EXECUTION

*/

#include <systemc.h>

SC_MODULE(Thread_Example){
    void thread_process(){
        while(true){
            cout << "SC_Thread Running!!!!!" << endl;
        }
    }
    
    SC_CTOR(Thread_Example){
        SC_THREAD(thread_process);

        
    }


};


int sc_main(int argc, char*argv[]){
    Thread_Example module("Thread_Example");
    // sc_start();                              /// Running in infinite loop you can put a limit of time 

    sc_start(10,SC_NS);                        // execute the thread for 10 Nanoseconds
    return 0;
}