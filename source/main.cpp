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
#include "../headers/Event.h"
#include <algorithm> 
#include <cstdlib> 
#include <stack>

// global state variables.
const int totalSimulationTime = 1000;
int simClock = 0;
int numInQueue = 0;

// create an FEL of type Event. Global variable so it is accessed by different functions.
std::vector<Event> futureEventList;
std::vector<Process> processList;
Event immiEvt(0,0,0,0,0);




bool compareProcesses( Process a, Process b) {  return (a.getPriority() > b.getPriority()); }

class Scheduler 
{
public:
    std::vector<Process > FCFSQueue;
    std::vector<Process> RoundRobinQueue;
    std::vector<Process> PirorityQueue;
    bool FCFS_aval;    // det if fcfs available
    bool RR_aval;      // det if rr available
    bool PQ_aval;      //   det if pq available
    int scheduleState; // determines which queue to use based on Event.

protected:
    int sID; // specific scheduler's ID.

public:
    // default constructor.
    Scheduler(int _ID) : sID(_ID), FCFS_aval(true), PQ_aval(true), RR_aval(true) {}

    // comparator function
    
    // performs the priority scheduling

    int runPriorQueue() { 

        /** Process based on its respective queue */
        /** logic of scheduling using its respective queue*/

        // sort based on pirority.
        std::sort(PirorityQueue.begin(), PirorityQueue.end(), compareProcesses);

        while( !PirorityQueue.empty() ) {

            Process curProc = PirorityQueue.back();
            PirorityQueue.pop_back();

            // need to update the system simClock. 
            simClock += curProc.getRemainingTime(); // finished executing.since it does it in one go.

        }


        return 1; 
    }

    int runFCFS() { 

        /** logic of scheduling using its respective queue*/
        while (!FCFSQueue.empty() ) {

            Process curProc = FCFSQueue.front(); 

            simClock += curProc.getRemainingTime(); 

            /** output relevant information */
        }


        return 1; 
    }

    int RoundRobin( ) { 

        /* time quantum */
        const int timeQuantum = 20; 
        
        while(!RoundRobinQueue.empty() && simClock < totalSimulationTime) {

            Process curProc = RoundRobinQueue.back(); 
            RoundRobinQueue.pop_back();

            // each process executes for sometime based on its assumed time 
            // allocated to it by the CPU, in this instance we assume that before 
            // runtime for simplicity. timeQuantum doesnt change for any process.
            simClock += timeQuantum; 

            curProc.setRemain( timeQuantum ); // updt. 

            //check if there's still some remaining time for the process.
            if ( curProc.getRemainingTime() < 0 ) { 

                // schedule it for departure. update FEL. maybe create depart queue. and put inside.
                
            } else { 
                RoundRobinQueue.push_back( curProc );// will be executed again.
            }

        } 

        return 1; 
        
    }


    // executes a job based on the FEL.
    int Execute()
    {

        switch (immiEvt.getJobId()) // based on job choose a specific queue.
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

        return 1; 
    }

    // work on it later
    void updateStatistics(); // updates certain statistics and send it to SimulateCore for stat variables.
};

// scheduler 
Scheduler coreA(1);

// runs our simulation.
int arrivalEvent(/** Imminent Event arg */)
{
    std::cout << "ptocess has arrived";
    std::stack<int> ProcessTimes; // stores the time for each individual tasks.  

    // Generate Processes, and time for each processes in such a way that it is within the bounds of the immiEvent Time.
    int total_time = immiEvt.getTime(); 
    int indyProcTime = rand() % total_time + 1; int track_indyTime = 0;


    while(track_indyTime <= total_time) { 
        ProcessTimes.push(indyProcTime); 
        track_indyTime += indyProcTime; 
        // next random time. 
        if ( track_indyTime >= total_time ) { break; }
        indyProcTime = rand() % (total_time - track_indyTime ) + 1;
    } 

    // go to assigned scheduling based on job-type.
    switch(immiEvt.getJobId() ) {

        case 1: 
            // generate random process for execution.  
            while( !ProcessTimes.empty() ) { coreA.PirorityQueue.push_back(Process(1,simClock+1,ProcessTimes.top(), 1));  ProcessTimes.pop(); }


            break; 
        case 2:
            while( !ProcessTimes.empty() ) { coreA.PirorityQueue.push_back(Process(1,simClock+1,ProcessTimes.top(), 1));  ProcessTimes.pop(); }

            break; 
        case 3: 
            while( !ProcessTimes.empty() ) { coreA.PirorityQueue.push_back(Process(1,simClock+1,ProcessTimes.top(), 1));  ProcessTimes.pop(); } 

            break; 
        
    }

    //while(!ProcessTimes.empty()) { coreA.}






    // Call a Specific Scheduler execute based on availability.
    /** Logic and stas for Code*/
    return 1; 
}

int departureDepart(/** Imminent Event Arg */)
{

    // now departure means calculate the timing stuffs. ie store in specific depart queue.
    std::cout << "procesed has departed";
    // Call a Specific Scheduler execute based on availability
    /** Logic and Stats for Code */
}

/** 
Event getNext(){
    Event temp(100000000, 0,0,0);
    for (int i =0; i<futureEventList.size(); i++){
        if(futureEventList[i].getTime() < temp.getTime()) {
            temp = futureEventList[i];
            
        }
    }
    return temp;
} */

int main()
{   

    srand(time(NULL)); 

    /* 
    for (int i = 1; i <= 10; ++i)
    {
        int pid = i;
        int execution = std::rand() % 20 + 1;   // random execution time between 1 and 20
        int arrival = std::rand() % i * 10 + 1; // random execution time between 1 and 20
        int priority = std::rand() % 3 + 1;     // random priority between 1 and 3
        Process p(pid, arrival, execution, priority);
        processList.push_back(p);

        Event aEvent = Event(arrival, priority, 0, pid);
        Event dEvent = Event(arrival + execution, priority, 1, pid);
        
        futureEventList.push_back(aEvent);
        futureEventList.push_back(dEvent);
    }*/

    // Generate 10 FELS first make them arrive.
    for ( int i=0; i<10; i++ ) { futureEventList.push_back(Event(1,simClock +10 + i,i,1,2)); } 


    // simClock will be updated within the processes.

    while (simClock < totalSimulationTime)
    { // adapted from in-class lectures.

        // check if we have not exceeded simulation time.

        // sort FEL first.  

        immiEvt = futureEventList.front();

        
        // OUTPUT : cout cur FEL pulled. 

        switch (immiEvt.getType())
        {
        case 1:
            arrivalEvent();
            break; 
        case 2:
            departureDepart();
            break;
        default:
            break;
        }
    }

    return 0;
}