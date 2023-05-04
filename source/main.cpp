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
#include <unistd.h>
#include <cmath>

// global state variables.
const int totalSimulationTime = 100;
int simClock = 0;
int numEvents = 0; // get's updated whenever there's a new event created in FEL.

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
            curProc.setState();
            //sleep(immiEvt.getTime()% 10); 
            std::cout << curProc.toString() << " in " << std::to_string(immiEvt.getTime()) << " secs" << std::endl;  
        }

            // when depart queue is full , you cant schedule a job for this queue.
            PQ_aval = false; 
            // schedule a departure event. with the specific imminent JobId.
            futureEventList.push(Event(immiEvt.getid(), simClock,1, 2, immiEvt.getJobId() )); 

            numEvents += 1; 

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

            curProc.setState();
            std::cout << curProc.toString() << " in " << std::to_string(immiEvt.getTime()) << " secs" << std::endl; 

            //sleep(immiEvt.getTime()% 10); 
        } 

        FCFS_aval = false; 
        // schedule a departure event. with the specific imminent JobId.
        futureEventList.push(Event(immiEvt.getid(), simClock,1, 2, immiEvt.getJobId() )); 

        numEvents += 1; 


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

            curProc.setRemain( timeQuantum ); // updt using time quantum.

            //check if there's still some remaining time for the process.
            if ( curProc.getRemainingTime() <= 0 ) { 

                // schedule it for departure. update FEL. maybe create depart queue. and put inside.
                curProc.setState();
                std::cout << curProc.toString() << " in " << std::to_string(immiEvt.getTime()) << " secs" << std::endl;  
                RRDepartQueue.push_back( curProc );
            } else { 
                RoundRobinQueue.push_back( curProc );// will be executed again.
            }
        } 

        //sleep(immiEvt.getTime()% 10); 

        // schedule a departure event. with the specific imminent JobId.
        futureEventList.push(Event(immiEvt.getid(), simClock,1, 2, immiEvt.getJobId() )); 
        numEvents += 1; 

        //std::cout << " Round Robin Queue " << std::endl;

        return 1; 
        
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
    int indyProcTime = rand() % (total_time + 1)+ rand() % 25; int Pid = rand() % 1000 + 1;
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
            while( !ProcessTimes.empty() ) { coreA.PirorityQueue.push_back(Process(Pid,simClock+indyProcTime,ProcessTimes.front(), 1));  ProcessTimes.pop(); }
            
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

// this struct will keep track of the performance statistics. 
struct PerformanceStats { 
    int EventID; 
    int Throughput; 
    int Turnaround; 
    int WaitTime; 
    int ResponseTime; 
    int ProcessorUtil;  

    PerformanceStats( int eid, int tru=0, int turn=0, int w=0, int res=0, int proc=0 ){
        EventID = eid; 
        Throughput = tru; 
        Turnaround = turn; 
        WaitTime = w; 
        ResponseTime = res; 
        ProcessorUtil = proc; 
    }
}; 

// Statistics obj.
std::vector<PerformanceStats> Tracker; 
PerformanceStats curStats(0); // gets current event to update.

void calcStats( int _eventID ) { 

        for ( int i =0; i< Tracker.size(); i++ ) { 
            if ( _eventID == Tracker[i].EventID ) { 
                curStats = Tracker[i]; 
                return;
            } 
        }
        Tracker.push_back(PerformanceStats(_eventID)); // create new performance statistics. 

        
}

void analyzeData( ) { 

    // analyzes data from performance stats. 
    float avg_turntime, avg_wait, avg_res; 
    int totalturn, total_wait, total_res, throughput=0, procutil=0; 
    for ( int i=0; i< Tracker.size(); i++ ) { 
        total_wait += Tracker[i].WaitTime; 
        total_res += Tracker[i].ResponseTime; 
        totalturn += Tracker[i].Turnaround; 
        throughput += Tracker[i].Throughput; 
        procutil += Tracker[i].ProcessorUtil; 
        
    }

    avg_turntime = std::round(totalturn / Tracker.size() ); 
    avg_wait = std::round(total_wait / Tracker.size()); 
    avg_res = std::round(total_res / Tracker.size()); 

    std::cout << std::to_string(std::round(throughput)) << "  " <<std::to_string(avg_turntime) << " " << std::to_string(avg_wait) << " " << std::to_string(avg_res)<< " " << std::to_string(std::round( procutil)) << std::endl;
    
}

int main()
{   
    srand(time(NULL)); 




    for ( int i=0; i<5; i++ ) { 
        // Generate 10 FELS first make them arrive.
        numEvents = 0; // reset.
        simClock = 0; // reset.
        for ( int i=0; i<10; i++ ) { 
            { 
                int rId = rand() % 1000; int rTime = rand() % totalSimulationTime/100 + 2; 
                int rPrio = rand() % 4; int rJId = 3; //  set rJid=1 for Priority Scheduling, RJid=2 for first come first serve, RjId=3 for Roundrobin.
                
                futureEventList.push( Event(rId,rTime,rPrio,1,rJId) ); 
                numEvents += 1; 
            }
        } 

        // statistics collector.
        int avg_turntime, avg_wait, avg_res; 
        int totalturn, total_wait, total_res, throughput=0, procutil=0;

    
        // simClock will be updated within the processes.
        while (simClock < totalSimulationTime)
        { // adapted from in-class lectures.

            immiEvt = futureEventList.front(); // stat's collection will be here

            
            // OUTPUT : cout current FEL pulled. 
            std::cout << immiEvt.toString() << " is scheduled" << std::endl;

            // check if event does not exist. using a util function.
            throughput += simClock;
            procutil += 1;

            numEvents += 1;       
            switch (immiEvt.getType())
            {
                total_wait += simClock;
                procutil += 1;
            case 1:
                total_wait += simClock;
                arrivalEvent();
                throughput += simClock;
                total_res += simClock;           
                break; 
            case 2:
                totalturn += simClock; 
                total_wait += simClock;
                departureDepart();
                throughput += simClock;
                break;
            default:
                break;
            } 

            if ( futureEventList.empty() ) { break; } // error-checking

            futureEventList.pop();
        } 

        // statistics calculator after every simulation. 
        avg_turntime = totalturn / (numEvents*10000); 
        avg_wait = total_wait / (200); // ussed simulation time as reference
        avg_res = total_res /  (numEvents*10000); 

        std::cout << "--------------------" <<std::endl; 
        std::cout<< "stats" << std::endl; 
        std::cout << std::to_string(throughput) << "  " <<std::to_string(avg_turntime) << " " << std::to_string(avg_wait) << " " << std::to_string(avg_res)<< " " << std::to_string(std::round( procutil)) << std::endl;
        std::cout << "--------------------" << std::endl;

    }

    return 0;
}