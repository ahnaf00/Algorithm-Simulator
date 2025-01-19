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
        int pid; // Process ID
        int arrivalTime; // Arrival time
        int burstTime; // Burst time
        int remainingTime; // Remaining time
        int completionTime; // Completion time
        int waitingTime; // Waiting time
        int turnaroundTime; // Turnaround time
};


void firtComeFirstSeerved(vector<Process>&processes);
void calculateSJF(vector<ProcessSJF>&processes);
void calculatePriorityScheduling(vector<ProcessPS>&processes);
void roundRobin(vector<ProcessRR>&processes, int timeQuantum);
void compareAllAlgorithms(const vector<int> &arrivalTimes, const vector<int> &burstTimes);

#endif