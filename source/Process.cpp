
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
    int interArrivalTime = std::rand() % 10 + 1; // random inter-arrival time between 1 and 10
    state = "New";
    remaining_time = execution;
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
std::string Process::getState() const { return state; }

// Getter for arrival_time
int Process::getRemainingTime() const { return remaining_time; }

// Getter for state_info
std::string Process::getStateInfo() const { return state; }

// Getter for priority
int Process::getPriority() const { return priority; }

int Process::getExecutionNumber() const { return executionNumber; }

int Process::getInterArrivalTime() const { return interArrivalTime; }
