/*
    HALF ADDER TESTBENCH

*/



#include <systemc.h>
#include "HalfAdder.cpp"
int sc_main(int argc, char* argv[]){
    sc_signal<bool> a, b, sum, carry;

    HalfAdder ha("ha"); // Instance of HA

    ha.a(a);
    ha.b(b);
    ha.sum(sum);
    ha.carry(carry);

    // CREATE WAVEFORM FILE 
    sc_trace_file *tf = sc_create_vcd_trace_file("Half_Adder_Waveform");
    sc_trace(tf,a,"A");
    sc_trace(tf,b,"B");
    sc_trace(tf, sum, "Sum");
    sc_trace(tf, carry, "Carry");


    //CASES
    a = 0; b = 0;  // 0 + 0
    sc_start(1, SC_NS);
      
    a = 0; b = 1;  // 0 + 1
    sc_start(1, SC_NS);

    a = 1; b = 0;  // 1 + 0
    sc_start(1, SC_NS);

    a = 1; b = 1;  // 1 + 1
    sc_start(1, SC_NS);
       
    a = 0, b = 0;
    sc_start(1,SC_NS);
    sc_close_vcd_trace_file(tf);
    return 0;
}
