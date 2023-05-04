// <Nana Boateng> <Amoah> && <Bhavesh> <Bhagtani>
// <04/22/23>
// <Course Code: CS-475W-1>
// <Lab Module # : 7>
// License: Copyright <2023> <Nana Boateng Amoah> && <Bhavesh> <Bhagtani>
// Resources used: <Lecture 7 and 8 from Class slides>
// Worked with <Bhavesh Bhagtani>
// <Contains object models to abstract entities for our simulation>
#ifndef PROCESS_H
#define PROCESS_H

#include <string> // standard string class
#include <vector> // standard template vector
#include <queue>  // standard queue data structure.

class Process
{
public:
    // settor's
    void setArrived(bool curState);

    void setDepart(bool curState);

    void setExecuted(bool curState);

    void setRemain(int curTime);

    void addWaitTime(int num);

    int getPid() const;
    // Getter for state

    std::string getState() const;
    // Getter for arrival_time

    int getRemainingTime() const;
    // Getter for execution_time

    std::string getStateInfo() const;
    // Getter for priority

    int getPriority() const;

    int getExecutionNumber() const;

    int getInterArrivalTime() const;

protected:
    int pid;
    std::string state; // possible enum
    
    bool arrive;
    bool depart;
    bool execute;
    int priority;
    int executionNumber;
    int interArrivalTime;
    int waitTime;

public:
    Process();
    Process(int pid, int arrival, int execution, int priority);
    int remaining_time;
};

#endif