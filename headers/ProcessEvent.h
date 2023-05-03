// <Nana Boateng> <Amoah> && <Bhavesh> <Bhagtani>
// <04/22/23>
// <Course Code: CS-475W-1>
// <Lab Module # : 7>
// License: Copyright <2023> <Nana Boateng Amoah> && <Bhavesh> <Bhagtani>
// Resources used: <Lecture 7 and 8 from Class slides> 
// Worked with <Bhavesh Bhagtani> 
// <Contains object models to abstract entities for our simulation> 
#ifndef PROCESSEVENT_H
#define PROCESSEVENT_H

#include <string> // standard string class
#include <vector> // standard template vector
#include <queue>  // standard queue data structure. 


class ProcessEvent { 
    public :

        // settor's
        void setState( std::string curState );

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

#endif