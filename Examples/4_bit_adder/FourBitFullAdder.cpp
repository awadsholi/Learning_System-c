#include <systemc.h>
#include "modules.h"

SC_MODULE(FourBitFullAdder) {
    sc_in<sc_bv<4>> A, B;
    sc_in<bool> C_in;
    sc_out<sc_bv<4>> Sum;
    sc_out<bool> C_out;
    
    sc_signal<bool> c[4];  
    sc_signal<bool> a_wire[4], b_wire[4], sum_wire[4];  

    FullAdder fa0, fa1, fa2, fa3;

    SC_CTOR(FourBitFullAdder) : fa0("fa0"), fa1("fa1"), fa2("fa2"), fa3("fa3") {
        SC_METHOD(split_input);
        sensitive << A << B;

        // First Full Adder
        fa0.a(a_wire[0]);  
        fa0.b(b_wire[0]);
        fa0.c_in(C_in);
        fa0.sum(sum_wire[0]);
        fa0.c_out(c[0]);

        // Second Full Adder
        fa1.a(a_wire[1]);
        fa1.b(b_wire[1]);
        fa1.c_in(c[0]);
        fa1.sum(sum_wire[1]);
        fa1.c_out(c[1]);

        // Third Full Adder
        fa2.a(a_wire[2]);
        fa2.b(b_wire[2]);
        fa2.c_in(c[1]);
        fa2.sum(sum_wire[2]);
        fa2.c_out(c[2]);

        // Fourth Full Adder
        fa3.a(a_wire[3]);
        fa3.b(b_wire[3]);
        fa3.c_in(c[2]);
        fa3.sum(sum_wire[3]);
        fa3.c_out(C_out);

        // Compute Output
        SC_METHOD(compute_output);
        sensitive << sum_wire[0] << sum_wire[1] << sum_wire[2] << sum_wire[3] << C_out;
    }

    void split_input() {
        sc_bv<4> a_val = A.read();
        sc_bv<4> b_val = B.read();
        for (int i = 0; i < 4; i++) {
            a_wire[i].write(a_val[i].to_bool());  
            b_wire[i].write(b_val[i].to_bool());
        }
    }

    void compute_output() {
        sc_bv<4> temp_sum_val;
        for (int i = 0; i < 4; i++) {
            temp_sum_val[i] = sum_wire[i].read();
        }
        Sum.write(temp_sum_val);        
    }
};