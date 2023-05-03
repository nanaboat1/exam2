// <Nana Boateng> <Amoah> && <Bhavesh> <Bhagtani>
// <04/22/23>
// <Course Code: CS-475W-1>
// <Lab Module # : 7>
// License: Copyright <2023> <Nana Boateng Amoah> && <Bhavesh> <Bhagtani>
// Resources used: <Lecture 7 and 8 from Class slides> 
// Worked with <Bhavesh Bhagtani> 
// <Contains object models to abstract entities for our simulation> 
#ifndef SIMULATECORE_H
#define SIMULATECORE_H

#include <string> // standard string class
#include <vector> // standard template vector
#include <queue>  // standard queue data structure. 
#include "../headers/Scheduler.h"
#include "../headers/ProcessEvent.h"


class SimulateCore { 
    public : 

        // gettors 
        int getsimID() const ; 
        double getWaitTime() const;  
        int getEventsCompleted() const; 
        int getAvgWaitTime() const;  

    protected : 
        
        std::queue<ProcessEvent>  FutureEventList; // tracks future activities for the processes.
        int simuID; 
        double totalWaitTime; 
        int totalEventCompleted; 
        int avgWaitTime; 
        Scheduler simSchedule; 


    public : 

        // constructor for simulateCore. 
        SimulateCore( int _simID, std::queue<ProcessEvent> _processes ); 

        // runs the simulator.  calls its scheduler. 
        void run();  // load some FEL into scheduler.


}; 



#endif