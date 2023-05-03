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
#include "../headers/Event.h"

// runs our simulation. 
void DES( ) { 



}


int main() {

   // create an FEL of type Event. 
   std::vector<Event> FutureEventList; 


   for  ( int i =0; i<5; i++) { 
    FutureEventList.push_back(Event(i, 0.4 + i, 3, 2,1)); 
   }

   const int totalSimTime = 10; 
   int curTime = 0; 

   while ( curTime < totalSimTime ) { 

        Event immiEvt = FutureEventList[0]; 

        immiEvt.toString(); 
        curTime++; 
   }

    


    return 0; 
}