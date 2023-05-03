#include <iostream>
#include "../headers/scheduler.h"
#include <vector>
#include "../headers/data.h"
#include <queue> 


void Scheduler::addToArrived( std::queue<ProcessEvent> _arrived ){ 
    // assign FEL's queue to Scheduler's queue. 
    arrived = _arrived ;

}
ProcessEvent Scheduler::getFromArrived( ) const {

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
