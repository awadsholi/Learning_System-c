#include <systemc.h>
#include "modules.h"

SC_MODULE(FullAdder){

    sc_in <bool> a,b,c_in;
    sc_out <bool> sum, c_out;

    sc_signal <bool> s1,c1,c2;

    HalfAdder half_adder1;
    HalfAdder half_adder2;
    OrGate or_gate;

    SC_CTOR(FullAdder): half_adder1("ha1"), half_adder2("ha2"), or_gate("or_gate"){
        half_adder1.a(a);
        half_adder1.b(b);
        half_adder1.sum(s1);
        half_adder1.carry(c1);   


        half_adder2.a(s1);
        half_adder2.b(c_in);
        half_adder2.sum(sum);
        half_adder2.carry(c2);


        or_gate.a(c1);
        or_gate.b(c2);
        or_gate.result(c_out);

        
    } 
 
};