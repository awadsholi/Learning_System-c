#include <systemc.h>
#include "modules.h"

SC_MODULE(FourBitFullAdder_TB) {
    sc_signal<sc_bv<4>> A, B;
    sc_signal<bool> C_in;
    sc_signal<sc_bv<4>> Sum;
    sc_signal<bool> C_out;

    FourBitFullAdder uut;

    SC_CTOR(FourBitFullAdder_TB) : uut("uut") {
        uut.A(A);
        uut.B(B);
        uut.C_in(C_in);
        uut.Sum(Sum);
        uut.C_out(C_out);

        SC_THREAD(run_tests);
    }

    void run_tests() {
        sc_trace_file *vcdfile = sc_create_vcd_trace_file("FourBitFullAdder_Waveform");
        vcdfile->set_time_unit(1, SC_NS);

        sc_trace(vcdfile, A, "A");
        sc_trace(vcdfile, B, "B");
        sc_trace(vcdfile, C_in, "C_in");
        sc_trace(vcdfile, Sum, "Sum");
        sc_trace(vcdfile, C_out, "C_out");

        sc_bv<4> test_A[] = { "0000", "0001", "0011", "0101", "0111", "1111", "1001", "1010" };
        sc_bv<4> test_B[] = { "0000", "0001", "0011", "0101", "0111", "1111", "1001", "1010" };
        bool test_C_in[] = { 0, 1 };

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k < 2; k++) {
                    A.write(test_A[i]);
                    B.write(test_B[j]);
                    C_in.write(test_C_in[k]);

                    wait(5, SC_NS);
                }
            }
        }

        sc_close_vcd_trace_file(vcdfile);
        sc_stop();
    }
};

int sc_main(int argc, char* argv[]) {
    FourBitFullAdder_TB tb("tb");
    sc_start();
    return 0;
}
