#include "../headers/data.h"
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>


    ProcessEvent::ProcessEvent(int arrival, int execution, int prio) {
        
        // Generate random ID
        std::mt19937 rng(std::time(0));
        std::uniform_int_distribution<int> distribution(1000, 9999);
        pid = distribution(rng);

        // Set initial state and state_info
        state = "New";
        state_info = "New process created.";

        // Set arrival_time, execution_time, and priority
        arrival_time = arrival;
        execution_time = execution;
        priority = prio;
        //cout<<"Priority assigned: " << this->priority << "\n";
    }

    int ProcessEvent::getPid() const { return pid; }

    // set state. 
    void ProcessEvent::setState ( std::string curState ) { state = curState;  }

    // Getter for state
    std::string ProcessEvent::getState() const { return state; }

    // Getter for arrival_time
    int ProcessEvent::getArrivalTime() const { return arrival_time; }

    // Getter for execution_time
    int ProcessEvent::getExecutionTime() const { return execution_time; }

    // Getter for state_info
    std::string ProcessEvent::getStateInfo() const { return state_info; }

    // Getter for priority
    int ProcessEvent::getPriority() const { return priority; } 

    // implementations for SimulateCore
    SimulateCore::SimulateCore( int _simID, std::priority_queue<ProcessEvent> _processes ) : simuID(_simID), FutureEventList(_processes), 
                                avgWaitTime(0), totalEventCompleted(0), totalWaitTime(0) {} 
    
    int SimulateCore::getsimID( ) const { return simuID; } 

    double SimulateCore::getWaitTime() const { return totalWaitTime; }

    int SimulateCore::getEventsCompleted() const { return totalEventCompleted; }

    int SimulateCore::getAvgWaitTime( ) const { return avgWaitTime; } 

    void SimulateCore::run( ) { 

        // run's the SimulateCore
        std::queue<ProcessEvent> Narrived; 

        while ( !FutureEventList.empty() ) {

            Narrived.push( FutureEventList.top()); 

        }

        simSchedule.addToArrived( Narrived );

        simSchedule.execute();

    }


