
    /*
    
    
        THREAD USES FOR SEQUENTIAL EXECUTION 
    
    
    
    
    */


    #include <systemc.h>

    SC_MODULE(ThreadExample) {
        void thread_process() {
            while (true) {
                cout << "SC_THREAD running!" << endl;
                wait(2, SC_NS); // Wait for 2 nanoseconds
            }
        }
    
        SC_CTOR(ThreadExample) {
            SC_THREAD(thread_process); // Register SC_THREAD
        }
    };
    
    int sc_main(int argc, char* argv[]) {
        ThreadExample module("Thread_Example");
    
        sc_start(10, SC_NS); // Run simulation for 10 ns
        return 0;
    }
    