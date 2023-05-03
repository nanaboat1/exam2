
#include <iostream>
#include "Scheduler.h"
#include <vector>
#include <queue> 

void Scheduler::addToArrived( std::queue<Process> _arrived ){ 
    // assign FEL's queue to Scheduler's queue. 
    arrived = _arrived ;

}
 
 
// Getter for state
int Scheduler::getLengthArrival() const {
    return arrived.size();
}

// Getter for arrival_time
Scheduler::Scheduler(){

    // generate schedule ID. 
    scheduleID = 1; 
}

// runs the simulation. // we can also change the schedule algorithm here as well.
void Scheduler::execute( ) { 

    while ( !arrived.empty() ) { // when queue is full and processes needs to be executed.

        // set certain process event flag to executed.
        //Process curProc = arrived.front(); 

        // implement tostring method here.
       

        // calculate certain time statistics here, and send to simulate core. <event, driven based on state>

        // print out certain elements, then delete process.. 
        //std::cout<< curProc.getPid() << " is done execution " << std::endl; 


        // next event if process execution is done then you pop, it out from the queue, then u do the next 
        // one. 
        //if ( curProc.getState() == "executed" ) { arrived.pop(); }
        //else { continue; } // do something special here for edge cases.

    }

}
