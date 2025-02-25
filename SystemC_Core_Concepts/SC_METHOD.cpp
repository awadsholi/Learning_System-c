#include <systemc.h>


SC_MODULE(MethodExample){
    sc_signal<int> signal_a;                                 // Signal declaration
    void process_method(){                                   // Process method
        cout << "Process method called " << signal_a.read()<< endl;

    }

    SC_CTOR(MethodExample){
        SC_METHOD(process_method);                             //Executes (instanteously) when a signal or event changes
        sensitive << signal_a;                                 // Trigger to signal_a change
    }
};


int sc_main(int argc, char* argv[]){
    MethodExample module("Method_Example");
    module.signal_a.write(10);                                  // call the process method
    sc_start();
    return 0;
}


