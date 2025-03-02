#include <systemc.h>
using namespace sc_core;

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

SC_MODULE(Testbench) {
    sc_signal<bool> a, b, result;
    AndGate and_gate;

    void test() {
        a.write(false);
        b.write(false);
        wait(1, SC_NS);
        std::cout << "a: " << a.read() << ", b: " << b.read()
                  << ", result: " << result.read() << std::endl;

        a.write(true);
        b.write(false);
        wait(1, SC_NS);
        std::cout << "a: " << a.read() << ", b: " << b.read()
                  << ", result: " << result.read() << std::endl;

        a.write(true);
        b.write(true);
        wait(1, SC_NS);
        std::cout << "a: " << a.read() << ", b: " << b.read()
                  << ", result: " << result.read() << std::endl;

        sc_stop(); 
    }

    SC_CTOR(Testbench)
        : and_gate("AndGate") {
        and_gate.a(a);
        and_gate.b(b);
        and_gate.result(result);

        SC_THREAD(test);
    }
};

int sc_main(int argc, char* argv[]) {
    Testbench tb("Testbench");
    sc_start(); 
    return 0;
}
