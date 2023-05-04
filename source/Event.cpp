// <Nana Boateng> <Amoah> && <Bhavesh> <Bhagtani>
// <04/22/23>
// <Course Code: CS-475W-1>
// <Lab Module # : 7>
// License: Copyright <2023> <Nana Boateng Amoah> && <Bhavesh> <Bhagtani>
// Resources used: <Lecture 7 and 8 from Class slides>
// Worked with <Bhavesh Bhagtani>
// <Contains object models to abstract entities for our simulation>

#include <string> // standard string class
#include <vector> // standard template vector
#include <queue>  // standard queue data structure.
#include "../headers/Event.h"

int Event::getid() const{
    return id;
}
int Event::getType() const{
    return  type;
}
int Event::getJobId() const{
    return jobId;
}
int Event::getTime() const{
    return time;
};


Event::Event(int _id, int arrival, int prio, int type, int jobId ) {

    this->id = _id; 
    this->time = arrival;
    this->type = type;
    this->prio = prio;
    this->jobId = jobId;

}
Event::Event() : id(0), time(0), prio(0), type(0), jobId(0) {}

std::string Event::toString( ) { return  std::to_string(id); }