#include <systemc>
using namespace sc_core;

SC_MODULE(MODULE_A){ ////type 1 of module is SC default MODULE
    SC_CTOR(MODULE_A){// CONSTRUCTOR
        std::cout<<name() <<" constructor" <<std::endl;//PRINT STATEMENT
    }
};

struct MODULE_B : public sc_module{//type2 struct module use c++ syntax 
    SC_CTOR(MODULE_B){
        std::cout<<name() << " constructor" <<std::endl;
    }
};

class MODULE_C : public sc_module{//type3 Class
    public:
        SC_CTOR(MODULE_C){
            std::cout << name()<< " constructor" << std::endl;
        }
};

int sc_main(int, char*[]){
    MODULE_A module_a("module_a");
    MODULE_B module_b("module_b");
    MODULE_C module_c("module_c");
    sc_start();
    return 0;
}