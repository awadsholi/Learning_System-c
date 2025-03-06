#include <systemc.h>
#include "modules.h"


int sc_main (int argc, char* argv[]){
    sc_signal <bool> a,b,c_in,sum,c_out;
    
    FullAdder full_adder("full_Adder");

    full_adder.a(a);
    full_adder.b(b);
    full_adder.c_in(c_in);
    full_adder.sum(sum);
    full_adder.c_out(c_out);

    sc_trace_file *wf = sc_create_vcd_trace_file("FullAdder");
    sc_trace(wf,a,"A");
    sc_trace(wf,b,"B");
    sc_trace(wf,c_in,"Cin");
    sc_trace(wf,sum,"Sum");
    sc_trace(wf,c_out, "Cout");

//1
    a = 0;
    b = 0;
    c_in = 0;

    sc_start(1,SC_NS);

//2
    a = 0;
    b = 0;
    c_in = 1;

    sc_start(1,SC_NS);

//3
    a = 0;
    b = 1;
    c_in = 0;

    sc_start(1,SC_NS);
//4

    a = 0;
    b = 1;
    c_in = 1;

    sc_start(1,SC_NS);

//5
    a = 1;
    b = 0;
    c_in = 0;

    sc_start(1,SC_NS);

//6
    a = 1;
    b = 0;
    c_in = 1;

    sc_start(1,SC_NS);

//7
    a = 1;
    b = 1;
    c_in = 0;

    sc_start(1,SC_NS);

//8
    a = 1;
    b = 1;
    c_in = 1;

    sc_start(1,SC_NS);


    sc_close_vcd_trace_file(wf);
    return 0;


}