// <Nana Boateng> <Amoah> && <Bhavesh> <Bhagtani>
// <04/22/23>
// <Course Code: CS-475W-1>
// <Lab Module # : 7>
// License: Copyright <2023> <Nana Boateng Amoah> && <Bhavesh> <Bhagtani>
// Resources used: <Lecture 7 and 8 from Class slides> 
// Worked with <Bhavesh Bhagtani> 
// <Contains object models to abstract entities for our simulation> 
#ifndef DATA_H
#define DATA_H

#include <string> // standard string class
#include <vector> // standard template vector
#include <queue>  // standard queue data structure. 




class ProcessEvent { 

    public :
        // settor's
        void setState( const std::string curState );

        int getPid() const ;
        // Getter for state

        std::string getState() const ;
        // Getter for arrival_time

        int getArrivalTime() const ;
        // Getter for execution_time

        int getExecutionTime() const ;
        // Getter for state_info

        std::string getStateInfo() const ;
        // Getter for priority
        
        int getPriority() const ;


    protected : 
        int pid;
        std::string state; // possible enum
        int arrival_time;
        int execution_time;
        std::string state_info;
        int priority;

    public : 
        ProcessEvent(int arrival, int execution, int prio);
    

};  


class SimulateCore { 

    public : 

        // gettors 

        int getsimID() const ; //{ return simuID; }
        double getWaitTime() const;  //{ return totalWaitTime; }
        int getEventsCompleted() const;  //{ return totalEventCompleted; }
        int getAvgWaitTime() const;  //{ return }

    protected : 
        
        std::priority_queue<ProcessEvent>  FutureEventList; // tracks future activities for the processes.
        int simuID; 
        double totalWaitTime; 
        int totalEventCompleted; 
        int avgWaitTime; 

    public : 

        // constructor for simulateCore. 
        SimulateCore( int _simID, std::priority_queue<ProcessEvent> _processes ); 




}; 



#endif