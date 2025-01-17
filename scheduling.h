#ifndef SCHEDULING_H
#define SCHEDULING_H

#include <bits/stdc++.h>
using namespace std;

class Process{
    public:
        int id;
        int arrivalTime;
        int burstTime;
        int waitingTime;
        int turnAroundTime;
        int completionTime;
};

class ProcessSJF{
    public:
        int id;
        int arrivalTime;
        int burstTime;
        int remainingTime;
        int completionTime;
        int waitingTime;
        int turnaroundTime;
};

class ProcessPS{
    public:
        int id;
        int arrivalTime;
        int burstTime;
        int priority;
        int remainingTime;
        int completionTime;
        int waitingTime;
        int turnaroundTime;
};

class ProcessRR {
    public:
        int pid;              // Process ID
        int burstTime;        // Burst Time
        int remainingTime;    // Remaining Time
        int waitingTime;      // Waiting Time
        int turnaroundTime;   // Turnaround Time
        int completionTime;   // Completion Time
        int arrivalTime;      // Arrival Time (default = 0)
};


void firtComeFirstSeerved(vector<Process>&processes);
void calculateSJF(vector<ProcessSJF>&processes);
void calculatePriorityScheduling(vector<ProcessPS>&processes);
void roundRobin(vector<ProcessRR>&processes, int timeQuantum);

#endif