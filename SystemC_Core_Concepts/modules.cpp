///used to encapsulate the functionality of a hardware componenet or subsystem,,,,
//Module used as a container for processes ,ports,signals ...etc


/////////////////Basic Structure ////////////////////////
/*
SC_MODULE(test){
    //member variables:ports,signals and internal variables .....
    
        Ports : For Communication with other modules 
        Signals :Internal connections or inter-module communication 
        Internal Variables :  To protect a state within a module 
     
    //processes: Methods,threads
    SC_CTOR(test){
        //Constructor body: Register Processes and initialize variables 
        //Processes ---------->> SC_METHOD , SC_THREAD , SC_CTHREAD 
        //Implement the module's behavior 
    }
};*/ 

//////PORT TYPES ////////////////
///****** PORTS USED FOR COMMUNICATION BETWEEN MODULES 


/*
SC_MODULE(port){
    sc_in<int> input;//////////sc_in<object> ----> input port for reading data 
    sc_out<int> output; //sc_out<object> -------> output port for writing data
    sc_inout<int> inout_Value; //sc_inout----------> Bidirectional port for reading and writing 

    SC_CTOR(port){
        //Register processing here 
    }
}*/
/////////////Signals /////
//////***** Signals used to connect ports between modules  or in modules

///Example for modules and ports!!
/*
#include <systemc>
using namespace sc_core;
SC_MODULE(Module_A){
    sc_out <int> data_out; //Output port to write data 

    void generate_data(){
        data_out.write(42);//write data to the output port
    }

    SC_CTOR(Module_A){
        SC_METHOD(generate_data);
    }
};

SC_MODULE(Module_B){
    sc_in <int> data_in;   

    void print_data(){
        std::cout<<"Received: "<< data_in.read()<<std::endl;
    }
    SC_CTOR(Module_B){
        SC_METHOD(print_data);
        sensitive << data_in; //sensitive to changes on signals
    }
};


int sc_main(int argc,char *argv[]){
    sc_signal<int> signal_data;

    Module_A module_a("Module_A");
    Module_B module_b("Module_B");
    ///Connect ports to the signal
    module_a.data_out(signal_data);
    module_b.data_in(signal_data);
    sc_start();///start simulation
    return 0;
}*/



////Processes in modules thats in CTOR
////**** Processes define the behavior of a module that registered in  Constructor (SC_CTOR())  
/*
    SC_METHOD() ----> FOR Combination Logic ---> executes immediately
    SC_THREAD() ----> FOR Sequential Logic  ---> allows wait() statements
    SC_CTHREAD() ---> It's similar to SC_THREAD and synchronized with a clock  
*/


    ////Simple example on SC_METHOD 
/**
#include <systemc>
SC_MODULE(CombinationLogic){
    sc_in <int> a,b;
    sc_out <int> result;

    void compute_and(){
        result.write(a.read() && b.read());
    }

    SC_CTOR(CombinationLogic){
        SC_METHOD(compute_and);///Register Process 
        sensitive << a << b;    
    }
};*/

//Hierarchical Design 

//Example
/**
#include <systemc>
using namespace sc_core;

SC_MODULE(SubModule) {
    sc_in<bool> in;
    sc_out<bool> out;

    void pass_value() {
        out.write(in.read());
    }

    SC_CTOR(SubModule) {
        SC_METHOD(pass_value);
        sensitive << in;
    }
};

SC_MODULE(TopModule) {
    sc_signal<bool> signal1, signal2;
    SubModule submodule1, submodule2;

    sc_signal<bool>* signal_in;
    sc_signal<bool>* signal_out;

    SC_CTOR(TopModule)
        : submodule1("Sub_Module1"), submodule2("Sub_Module2") {
        // Initialize input and output signals to nullptr
        signal_in = nullptr;
        signal_out = nullptr;
    }

    void bind_signals(sc_signal<bool>& sig_in, sc_signal<bool>& sig_out) {
        // Set the input and output signal references
        signal_in = &sig_in;
        signal_out = &sig_out;

        // Connect submodule1
        submodule1.in(*signal_in);  // External Input
        submodule1.out(signal1);   // Internal Signal

        // Connect submodule2
        submodule2.in(signal1);    // Internal signal from submodule1
        submodule2.out(*signal_out); // External Output
    }
};

int sc_main(int argc, char* argv[]) {
    // External signals to interface with the top module
    sc_signal<bool> signal_top_input;
    sc_signal<bool> signal_top_output;

    // Instantiate the top module
    TopModule topmodule("TOP_MODULE");

    // Bind external signals to the top module
    topmodule.bind_signals(signal_top_input, signal_top_output);

    // Initialize input signal
    signal_top_input.write(true);

    // Start simulation for 10 nanoseconds
    sc_start(10, SC_NS);

    // Print the output signal value after simulation
    std::cout << "Output from Top Module: " << signal_top_output.read() << std::endl;

    return 0;
}
*/

#include <systemc>
using namespace sc_core;


