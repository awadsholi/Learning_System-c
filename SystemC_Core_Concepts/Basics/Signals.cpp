/*

    SIGNALS USED FOR COMUNICATION BETWEEN PROCESSES 
    SIGNALS USED AS A WIRE BETWEEN MODULES 


*/


#include <systemc.h>

SC_MODULE (Sender){
    sc_out <int> out_sig; //SEND FROM THIS MODULE (OUTPUT FROM THIS MODULE)

    void write_data(){
        out_sig.write(10);

    }
    SC_CTOR(Sender){
        SC_METHOD(write_data);
        sensitive << out_sig;
    }

};


SC_MODULE(Receiver){

    sc_in <int> in_sig; /// INPUT FROM OTHER MODULE

    void read_data(){
        cout << "Receiver Value :" << in_sig.read()<< endl;
    }

    SC_CTOR(Receiver){
        SC_METHOD(read_data);
        sensitive << in_sig;

    }


};



int sc_main(int argc , char* argv[]){
    sc_signal <int> signal;

    Sender sender("Sender");
    Receiver receiver("Receiver");

    sender.out_sig(signal);
    receiver.in_sig(signal);
    sc_start();
    return 0; 
}

/*


    SENDER  ------------------> (SIGNAL_OUT) -----------------> SIGNAL -----------------> (SIGNAL_IN) -----------------> RECEIVER
    (OUTPUT)                                               (WIRE)                                           (INPUT)  


*/