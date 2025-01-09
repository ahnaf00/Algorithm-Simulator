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

void firtComeFirstSeerved(vector<Process>&processes);
void calculateSJF(vector<ProcessSJF>&processes);

#endif