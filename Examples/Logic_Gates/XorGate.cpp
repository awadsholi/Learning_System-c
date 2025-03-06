#include <systemc.h>

SC_MODULE(XorGate){
    sc_in <bool> a,b;
    sc_out <bool> result;
    void xor_method(){
        result.write(a.read() ^ b.read());

    }
    SC_CTOR(XorGate){
        SC_METHOD(xor_method);
        sensitive << a << b;
    }


};