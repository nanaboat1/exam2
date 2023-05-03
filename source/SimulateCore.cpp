
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>
#include "SimulateCore.h"

// implementations for SimulateCore
SimulateCore::SimulateCore( int _simID, std::queue<ProcessEvent> _processes ) : simuID(_simID), FutureEventList(_processes), 
                            avgWaitTime(0), totalEventCompleted(0), totalWaitTime(0) {} 

int SimulateCore::getsimID( ) const { return simuID; } 

double SimulateCore::getWaitTime() const { return totalWaitTime; }

int SimulateCore::getEventsCompleted() const { return totalEventCompleted; }

int SimulateCore::getAvgWaitTime( ) const { return avgWaitTime; } 

void SimulateCore::run( ) { 

    // run's the SimulateCore
    std::queue<ProcessEvent> Narrived; 

    // put it in a function. so it is more event driven.
    while ( !FutureEventList.empty() ) {
        Narrived.push( FutureEventList.front()); 
    }

    simSchedule.addToArrived( Narrived );

    // check to see if simeSchedule's arrived is empty.

    if ( simSchedule.getLengthArrival() == 0 ) { 
        simSchedule.execute();
    } else { 
        simSchedule.addToArrived( Narrived );
    }
    

}


