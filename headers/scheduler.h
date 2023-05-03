#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "./data.h"
#include <queue>
#include <string>

class Scheduler { 

    public :

        // settor's
        void addToArrived( ProcessEvent p);

        ProcessEvent getFromArrived() ;
        // Getter for state

        int getLengthArrival()  ;
        // Getter for arrival_time



    protected : 

        std::queue<ProcessEvent> arrived;

    public : 

        Scheduler();
    

}; 



#endif