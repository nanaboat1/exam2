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

#include "../headers/data.h"
#include "../headers/scheduler.h"
#include <vector>
#include <queue>

std::vector<ProcessEvent> fel;
//poplate fel

std::queue<ProcessEvent> queue; //sorted fel
// write logic to sort it by arrival time


int executionTime = 0;

void pushToArrived(int execTime, Scheduler s){
    ProcessEvent temp = queue.front();
    while (temp.getArrivalTime() < execTime)
    {
        
    }
    
}


std::queue<ProcessEvent> proceess(){

    std::queue<ProcessEvent> pList;

    ProcessEvent p0 = ProcessEvent(0, 4, 1);
    ProcessEvent p1 = ProcessEvent(1, 4, 1);
    ProcessEvent p2 = ProcessEvent(3, 4, 12);
    ProcessEvent p3 = ProcessEvent(5, 4, 13);
    ProcessEvent p4 = ProcessEvent(8, 4, 1);
    ProcessEvent p5 = ProcessEvent(11, 4, 12);
    ProcessEvent p6 = ProcessEvent(15, 4, 13);

    pList.push(p0);
    pList.push(p1);
    pList.push(p2);
    pList.push(p3);
    pList.push(p4);
    pList.push(p5);
    pList.push(p6);

    return pList;

}

int main() {

    Scheduler s;
    std::queue<ProcessEvent> nArrived = proceess();

    s.addToArrived(nArrived.front());
    nArrived.pop();

    int counter = 0;
    while (s.getLengthArrival() > 0)
    {
        ProcessEvent currentProcess = s.getFromArrived();
        //std::cout<< "ProcessEvent " << currentProcess.getPid() << " is being executed. \n";
        
        counter += currentProcess.getExecutionTime();
        //std::cout<<"Current time into system: " << counter << "ms \n";
     
        std::cout << currentProcess.getArrivalTime() << " -> ";
        while(!nArrived.empty())
        {
    
           ProcessEvent temp = std::move(nArrived.front());
           if(temp.getArrivalTime() <= counter ){
                s.addToArrived(temp);
                // std::cout << "ProcessEvent " << temp.getPid() << "has been added to the queue. \n";
                nArrived.pop();
           }
           else{
                break;
           }

        }
        
    }
    


    return 0; 
}