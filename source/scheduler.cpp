#include <iostream>
#include "../headers/scheduler.h"
#include <vector>
#include "../headers/data.h"


void Scheduler:: addToArrived( ProcessEvent proc){
    arrived.push(proc);
}
ProcessEvent Scheduler:: getFromArrived( ){
    ProcessEvent temp = std::move(arrived.front());
    arrived.pop();
    return  temp;
}   
    // Getter for state

int Scheduler::getLengthArrival()  {
    return arrived.size();
}
    // Getter for arrival_time
Scheduler::Scheduler(){
    std::cout<<"Scheduler is active \n";
}