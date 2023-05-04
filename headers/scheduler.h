#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <queue>
#include <string>
#include "../headers/Process.h"
#include <vector> 

class Scheduler { 

    public : 

        std::vector<Process> FCFSQueue;
        std::vector<Process> RoundRobinQueue; 
        std::vector<Process> PirorityQueue;
        bool FCFS_aval; // det if fcfs available
        bool RR_aval;   // det if rr available
        bool PQ_aval; //   det if pq available
        int scheduleState; // determines which queue to use based on Event. 


    protected : 
        int sID; // specific scheduler's ID. 

    public : 

        // default constructor.
        Scheduler( );

        // runs ready state objects in the arrived queue and departs them and updates them. i.e depending on the execute
        int Execute( );  // based on a certain algo schedule.

        // work on it later
        void updateStatistics(); // updates certain statistics and send it to SimulateCore for stat variables.
        
    

}; 

#endif