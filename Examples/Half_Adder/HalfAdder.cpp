/*

    HALF ADDER MODULE FILE

*/

#include <systemc.h>


SC_MODULE(HalfAdder){
    sc_in<bool> a;
    sc_in<bool> b;
    sc_out<bool> sum;
    sc_out<bool> carry;

    SC_CTOR(HalfAdder){
        SC_METHOD(compute);
        sensitive << a <<b;
    }
    void compute(){
        sum.write(a.read() ^ b.read());
        carry.write(a.read() & b.read());

    }
};
