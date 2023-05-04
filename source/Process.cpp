
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>
#include "Process.h"

Process::Process()
{

    // Generate random ID
    std::mt19937 rng(std::time(0));
    std::uniform_int_distribution<int> distribution(1000, 9999);
    pid = distribution(rng);

    // Set initial state and state_info
    state = "New";
}
Process::Process(int pid, int arrival, int execution, int priority)
{
    this->pid = pid;
    this->execute=execution;
    this->priority = priority;
    this->arrive = arrival;
    state = "New";
    this->remaining_time = execution;
    executionNumber = 0;
}

int Process::getPid() const { return pid; }

void Process::addWaitTime( int num){
    waitTime +=num;
}


// set state.
void Process::setArrived(bool curState) { arrive = curState; }

void Process::setDepart(bool curState) { depart = curState; }

void Process::setExecuted(bool curState) { execute = curState; }

// Getter for state
void Process::setState(){ 
    
    if ( arrive == true) { 
        state = "arrived";
    } else if (execute == true)
    {
        state = "executed"; 
    }
    
    
}

// Getter for arrival_time
int Process::getRemainingTime() const { return remaining_time; }

// Getter for state_info
std::string Process::getStateInfo() const { return state; }

// Getter for priority
int Process::getPriority() const { return priority; }

int Process::getExecutionNumber() const { return executionNumber; }

int Process::getInterArrivalTime() const { return interArrivalTime; }

// update remaining time to be executed.
void Process::setRemain( int curTime ) { 

    remaining_time -= curTime; 

    // error for ensuring there are no negative remaining time.
    if ( remaining_time < 0 ) { remaining_time = 0; }
}

std::string Process::toString() { 

    std::string out = "[ pid: " + std::to_string(pid) + "activity:" + state + "]";
    return out; 
}
