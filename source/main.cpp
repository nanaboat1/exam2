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
#include "../headers/Scheduler.h"

// runs our simulation. 
void DES( ) { 

    // generate random processes and store in a queue. 
    std::vector<Process> maap; 
    
    // generate arrival and execution through random process later.

    for ( int i=0; i<10; i++ ) { maap.push_back(Process(5, 5, 2)); }

    std::queue<Process> coreAMem; 

    coreAMem.push( maap[0] ); 
    coreAMem.push( maap[1] ); 
    coreAMem.push( maap[2] ); 

    SimulateCore coreA(2, coreAMem ); 

    coreA.run(); 

}


std::queue<Process> proceess(){

    std::queue<Process> pList;

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

   DES(); 
    


    return 0; 
}