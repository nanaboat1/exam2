// <Nana Boateng> <Amoah> && <Bhavesh> <Bhagtani>
// <04/22/23>
// <Course Code: CS-475W-1>
// <Lab Module # : 7>
// License: Copyright <2023> <Nana Boateng Amoah> && <Bhavesh> <Bhagtani>
// Resources used: <Lecture 7 and 8 from Class slides>
// Worked with <Bhavesh Bhagtani>
// <Contains object models to abstract entities for our simulation>
#ifndef EVENT_H
#define EVENT_H

#include <string> // standard string class
#include <vector> // standard template vector
#include <queue>  // standard queue data structure.

class Event
{
public:
    int getid() const;
    int getType() const;
    int getJob() const;

protected:
    int id;
    int type;
    double time;
    int jobId;
    int prio; 

public:
    Event(int _id, double arrival, int execution, int prio, int type);

    std::string toString( ); 
};

#endif