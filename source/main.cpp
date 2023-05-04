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
#include <iomanip> 

// global state variables.
const int totalSimulationTime = 1000;
int simClock = 0;
int numInQueue = 0;

// create an FEL of type Event. Global variable so it is accessed by different functions.
std::queue<Event> futureEventList;
std::vector<Process> processList;
Event immiEvt(0,0,0,0,0);




bool compareProcesses( Process a, Process b) {  return (a.getPriority() > b.getPriority()); }

class Scheduler 
{
public:
    
    // arrival queues
    std::vector<Process > FCFSQueue;
    std::vector<Process> RoundRobinQueue;
    std::vector<Process> PirorityQueue;

    // departure queues.
    std::vector<Process> FCFSDepartQueue; 
    std::vector<Process> RRDepartQueue; 
    std::vector<Process> PriorDepartQueue; 

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

            // output will be here
            //std::cout << " Prior Queue " << std::endl;

            // add to departure queue
            PriorDepartQueue.push_back( curProc );
        }

            // when depart queue is full , you cant schedule a job for this queue.
            PQ_aval = false; 
            // schedule a departure event. with the specific imminent JobId.
            futureEventList.push(Event(immiEvt.getid(), simClock,1, 2, immiEvt.getJobId() )); 



        return 1; 
    }

    int runFCFS() { 

        /** logic of scheduling using its respective queue*/
        while (!FCFSQueue.empty() ) {

            Process curProc = FCFSQueue.back(); 

            simClock += curProc.getRemainingTime(); 

            FCFSQueue.pop_back();

            /** output relevant information */
            //std::cout << " First Come First Serve Queue " << std::endl;
            
            // add to departure queue when done execution.
            FCFSDepartQueue.push_back( curProc );

        } 

        FCFS_aval = false; 
        // schedule a departure event. with the specific imminent JobId.
        futureEventList.push(Event(immiEvt.getid(), simClock,1, 2, immiEvt.getJobId() )); 


        return 1; 
    }

    int RoundRobin( ) { 

        /* time quantum */
        const int timeQuantum = 20; 
        
        while(!RoundRobinQueue.empty()) {

            Process curProc = RoundRobinQueue.back(); 
            RoundRobinQueue.pop_back();

            // each process executes for sometime based on its assumed time 
            // allocated to it by the CPU, in this instance we assume that before 
            // runtime for simplicity. timeQuantum doesnt change for any process.
            simClock += timeQuantum; 

            curProc.setRemain( timeQuantum ); // updt. 

            //check if there's still some remaining time for the process.
            if ( curProc.getRemainingTime() <= 0 ) { 

                // schedule it for departure. update FEL. maybe create depart queue. and put inside.
                RRDepartQueue.push_back( curProc );
            } else { 
                RoundRobinQueue.push_back( curProc );// will be executed again.
            }
        } 

        // schedule a departure event. with the specific imminent JobId.
        futureEventList.push(Event(immiEvt.getid(), simClock,1, 2, immiEvt.getJobId() )); 

        //std::cout << " Round Robin Queue " << std::endl;

        return 1; 
        
    }

    // executes a job based on the FEL.
    int Execute()
    {

    }

    // work on it later
    void updateStatistics(); // updates certain statistics and send it to SimulateCore for stat variables.
};

// scheduler aka processor Cores.
Scheduler coreA(1);

// runs our simulation.
int arrivalEvent(/** Imminent Event arg */)
{
    //std::cout << "ptocess has arrived";
    std::queue<int> ProcessTimes; // stores the time for each individual tasks.  

    // Generate Processes, and time for each processes in such a way that it is within the bounds of the immiEvent Time.
    int total_time = immiEvt.getTime(); 
    int indyProcTime = rand() % (total_time + 1); int track_indyTime = 0;
    ProcessTimes.push(indyProcTime);


    //while(track_indyTime <= total_time) { 
        //ProcessTimes.push(indyProcTime); 
        //track_indyTime += indyProcTime; 
        // next random time. 
        //if ( track_indyTime >= total_time ) { break; }
       // indyProcTime = rand() % (total_time - //track_indyTime ) + 1;
    //} 

    // go to assigned Event based on job-type.
    switch(immiEvt.getJobId() ) {
        case 1: 
            // generate random process for execution.  
            while( !ProcessTimes.empty() ) { coreA.PirorityQueue.push_back(Process(1,simClock+1,ProcessTimes.front(), 1));  ProcessTimes.pop(); }
            
            if (coreA.PQ_aval == true ) { 
                coreA.runPriorQueue();
            } else {
                /* queue is full will have to perform the process again */
                futureEventList.push(immiEvt ); // reschedule that immievent again.
            }
            break; 
        case 2:
            while( !ProcessTimes.empty() ) { coreA.FCFSQueue.push_back(Process(1,simClock+1,ProcessTimes.front(), 1));  ProcessTimes.pop(); }
            if (coreA.FCFS_aval == true ) { 
                coreA.runFCFS();
            } else {
                /* queue is full will have to perform the process again */
                futureEventList.push(immiEvt ); // reschedule that imminent event again.
            }
            break; 
        case 3: 
            while( !ProcessTimes.empty() ) { coreA.RoundRobinQueue.push_back(Process(1,simClock+1,ProcessTimes.front(), 1));  ProcessTimes.pop(); } 
            if (coreA.RR_aval == true ) {
                coreA.RoundRobin(); 
            } else {
                futureEventList.push( immiEvt ); // reschedule that imminent event again.
            }
            break; 
        
    }

    /** Logic and stas for Code*/
    return 1; 
}

int departureDepart(/** Imminent Event Arg */)
{

    switch (immiEvt.getJobId() )
    {
    case 1:
        // when processes depart it means that respective scheduling is free to be used again.
        coreA.PriorDepartQueue.clear();
        coreA.PQ_aval = true; 
        //std::cout << "process has departed PQ " << std::endl;
        break;
    case 2: 
        // when processes depart it means that respective scheduling is free to be used again.
        coreA.FCFSDepartQueue.clear();
        coreA.FCFS_aval = true;
        //std::cout << "process has departed FCFS" << std::endl;
        break; 
    case 3:
        // when processes depart it means that respective scheduling is free to be used again.
        coreA.RRDepartQueue.clear(); 
        coreA.RR_aval = true; 
        //std::cout << "process has departed RR" << std::endl;
        break;
    
    default:
        break;
    }

    // now departure means calculate the timing stuffs. ie store in specific depart queue.
    // Call a Specific Scheduler execute based on availability
    /** Logic and Stats for Code */
    return 1; 
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
    for ( int i=0; i<10; i++ ) { 
        
        { 
            int rId = rand() % 1000; int rTime = rand() % totalSimulationTime/100 + 2; 
            int rPrio = rand() % 4; int rJId = rand() % 3 + 1;
            
            futureEventList.push( Event(rId,rTime,rPrio,1,rJId) ); 

        }

    } 


    // simClock will be updated within the processes.

    while (simClock < totalSimulationTime)
    { // adapted from in-class lectures.

        immiEvt = futureEventList.front();

        
        // OUTPUT : cout cur FEL pulled. 
        std::cout << immiEvt.toString() << " is scheduled" << std::endl;

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

        if ( futureEventList.empty() ) { break; }

        futureEventList.pop();
    }

    return 0;
}