#include <systemc.h>
#include "HalfAdder.cpp"

int sc_main(int argc, char*argv[]){
    sc_signal <bool> a,b,sum,carry;

    HalfAdder half_adder("half_adder");
    half_adder.a(a);
    half_adder.b(b);
    half_adder.sum(sum);
    half_adder.carry(carry);

    sc_trace_file *tf = sc_create_vcd_trace_file("HalfAdder_Wave");
    sc_trace(tf,a,"A");
    sc_trace(tf,b,"B");
    sc_trace(tf,sum,"Sum");
    sc_trace(tf,carry,"Carry");

    a = 0 , b = 0;
    sc_start(1,SC_NS);

    a=0 , b=1;
    sc_start(1,SC_NS);

    a=1 , b=0;
    sc_start(1,SC_NS);

    a=1 , b=1;
    sc_start(1,SC_NS);
    
    a=0 , b=0;
    sc_start(1,SC_NS);
    
    sc_close_vcd_trace_file(tf);

    return 0;

}