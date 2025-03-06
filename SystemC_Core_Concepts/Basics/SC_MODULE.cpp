#include <systemc.h>

SC_MODULE(Simple_Module){               //Declaring a Module 
    SC_CTOR(Simple_Module){             //Constructor to Initialize the Module 
        cout << "Hello Awad" <<endl;    //Printing  A message
    }
};

int sc_main(int argc,char* argv[]){     //SystemC main
    Simple_Module sm("Fir");            // Object From The module 
    return 0;
}