#include <systemc.h>

SC_MODULE(AndGate){
    sc_in <bool> a,b;
    sc_out <bool> result;
    void and_method(){
        result.write(a.read() && b.read());

    }
    SC_CTOR(AndGate){
        SC_METHOD(and_method);
        sensitive << a << b;
    }


};