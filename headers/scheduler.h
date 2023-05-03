#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "./data.h"
#include <queue>
#include <string>

class Scheduler { 

    public :

        // settor's
        void addToArrived( std::queue<ProcessEvent> _arrived );

        // departs finished processes from queue. based on state flag.
        void departFromQueue ( ); 

        // load new processes into the execution memory.
        ProcessEvent getFromArrived() const ;
        
        // get size of current arrival.
        int getLengthArrival() const ;
        

    protected : 

        std::queue<ProcessEvent> arrived;
        int scheduleID; 


    public : 

        // runs ready state objects in the arrived queue and departs them and updates them. i.e depending on the execute
        void execute( );  // based on a certain algo schedule.

        // 
        void updateStatistics(); // updates certain statistics and send it to SimulateCore for stat variables.
        
    

}; 

#endif