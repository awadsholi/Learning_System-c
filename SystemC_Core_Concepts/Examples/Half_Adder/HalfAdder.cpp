#include <systemc.h>
#include "AndGate.cpp"
#include "XorGate.cpp"

SC_MODULE(HalfAdder){

    sc_in <bool> a,b;
    sc_out <bool> sum, carry;
    
    XorGate xor_gate;
    AndGate and_gate;

    SC_CTOR(HalfAdder): xor_gate("xor_gate"), and_gate("and_gate"){
        xor_gate.a(a);
        xor_gate.b(b);
        xor_gate.result(sum);
        
        and_gate.a(a);
        and_gate.b(b);
        and_gate.result(carry);
    }
};