// <Nana Boateng> <Amoah> && <Bhavesh> <Bhagtani>
// <04/22/23>
// <Course Code: CS-475W-1>
// <Lab Module # : 7>
// License: Copyright <2023> <Nana Boateng Amoah> && <Bhavesh> <Bhagtani>
// Resources used: <Lecture 7 and 8 from Class slides> 
// Worked with <Bhavesh Bhagtani> 
// <Discrete Event Model Simultion> 

// standard io libraries.
#include <iostream>
#include <vector>
#include <queue>
#include "../headers/Process.h"
#include "../headers/SimulateCore.h"
#include "../headers/Event.h"


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
        Scheduler::Scheduler(int _ID ): sID(_ID), FCFS_aval(true), PQ_aval(true), RR_aval(true) {  }

        // executes a job based on the FEL.
        int Execute( ) { 

            switch (immiEvt.getJob()) // based on job choose a specific queue.
            {
            case 1: // Pirority Queue
                /* code */
                break;
            case 2: // Call RoundRobin
                /* code */
                break; 
            case 3: // Call FCFS
                /** code */
                break; 

            default: // call first come first serve.
                /* code */
                break;
            }



        } 


        // work on it later
        void updateStatistics(); // updates certain statistics and send it to SimulateCore for stat variables.
        
    

}; 

// create an FEL of type Event. Global variable so it is accessed by different functions.
std::vector<Event> FutureEventList; 
Event immiEvt; 








// runs our simulation. 
int arrivalEvent( /** Imminent Event arg */ ) { 

    // if a processor is free , just execute.
        // check for a free processor.

    // else put it in the idle queue.
        // queue is determined 
}

int departureDepart ( /** Imminent Event Arg */) {


}


int main() {

   for  ( int i =5; i>0; i--) { 
    FutureEventList.push_back(Event(i, 0.4 + i, 3, 2,1)); 
   }
   // sort whenever tired.

   const int totalSimTime = 10; 
   int curTime = 0; 
   int count = 0;

   //curTime will be updated within the processes.

   while ( curTime < totalSimTime ) { // adapted from in-class lectures.

        immiEvt = FutureEventList.back(); 

        FutureEventList.pop_back();
        std::cout << immiEvt.toString() << std::endl; 

        switch (immiEvt.getType())
        {
        case 1:
            /* code */ // execute based on type of immiEvent
            break;
        case 2: 

        case 2: 
        
        default:
            break;
        }
        
   }

    


    return 0; 
}