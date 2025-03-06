#include <systemc.h>

SC_MODULE(AndGate) {
    sc_in<bool> a, b;
    sc_out<bool> result;

    void compute_and() {
        result.write(a.read() && b.read());
    }

    SC_CTOR(AndGate) {
        SC_METHOD(compute_and);
        sensitive << a << b;
    }
};
