/*
    EVENT IS A TRIGGER THAT NOTIFIES PROCESSES
    EVENT DOESN'T STORE A VALUE
    SC_THRAD CAN PAUSED WITH WAIT FUNCTION AND RESUME

*/


#include <systemc.h>

SC_MODULE (Event_Example){
    sc_event event;

    void event_trigger(){
        cout <<"Triggering Event ..." << endl;
        event.notify(10,SC_NS); // NOTIFYING EVENT AFTER 5 NS
    }

    void event_handler(){
        while(true){
            wait(event);
            cout <<"Event handled at "<< sc_time_stamp() << endl; /// sc_time_stamp() is a systemc function that return a current simulation time
        }
    }

    SC_CTOR(Event_Example){
        SC_METHOD(event_trigger);
        /*
            I USED SC_METHOD WITH TRIGGERING RUNS IMMEDIATELY WHEN TRIGGERED
            IF I USED SC_THREAD INSTEAD OF METHOD I WILL WAIT A DELAY TIME FOR EXCECUTION 
            SC_METHOD RUNS WITH ZERO TIME DELAY FOR EXECUTION (COMBINATIONAL) AND IS GOOD FOR TRIGGERING EVENTS
        */
        SC_THREAD(event_handler);
        /*

           SC_THRAD ALLOWS WAITING WITH FUNCTION (WAIT) IT CAN PAUSE AND REACT TO EVENTS
           ///////////////SEQUENTIAL EXECUTION/////////////////////
           HANDLING SHOULD USED WITH SC_THREAD TO MAKE THE EVENT_DRIVEN BEHAVIOR TO WAIT SIGNAL BEFORE ACTING

        */
        sensitive << event;
    }

};

int sc_main(int argc, char* argv[]){
    Event_Example module("Event_Module");

    sc_start(100,SC_NS);
    return 0;
}