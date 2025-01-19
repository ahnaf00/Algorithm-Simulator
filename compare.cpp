#include "scheduling.h"

void compareAllAlgorithms(const vector<int> &arrivalTimes, const vector<int> &burstTimes)
{
    int n = arrivalTimes.size();

    // Prepare process vectors for each algorithm
    vector<Process> fcfsProcesses(n);
    vector<ProcessSJF> sjfProcesses(n);
    vector<ProcessPS> psProcesses(n);
    vector<ProcessRR> rrProcesses(n);

    for (int i = 0; i < n; i++)
    {
        fcfsProcesses[i] = {i + 1, arrivalTimes[i], burstTimes[i], 0, 0, 0};
        sjfProcesses[i] = {i + 1, arrivalTimes[i], burstTimes[i], burstTimes[i], 0, 0, 0};
        psProcesses[i] = {i + 1, arrivalTimes[i], burstTimes[i], rand() % 10 + 1, burstTimes[i], 0, 0, 0}; // Random priorities
        rrProcesses[i] = {i + 1, arrivalTimes[i], burstTimes[i], burstTimes[i], 0, 0, 0};
    }

    cout << "\nComparing Algorithms...\n";

    // FCFS
    firtComeFirstSeerved(fcfsProcesses);
    float avgFcfsWaiting = 0, avgFcfsTurnaround = 0;
    for (const auto &process : fcfsProcesses)
    {
        avgFcfsWaiting += process.waitingTime;
        avgFcfsTurnaround += process.turnAroundTime;
    }
    avgFcfsWaiting /= n;
    avgFcfsTurnaround /= n;

    // SJF
    calculateSJF(sjfProcesses);
    float avgSjfWaiting = 0, avgSjfTurnaround = 0;
    for (const auto &process : sjfProcesses)
    {
        avgSjfWaiting += process.waitingTime;
        avgSjfTurnaround += process.turnaroundTime;
    }
    avgSjfWaiting /= n;
    avgSjfTurnaround /= n;

    // Priority Scheduling
    calculatePriorityScheduling(psProcesses);
    float avgPsWaiting = 0, avgPsTurnaround = 0;
    for (const auto &process : psProcesses)
    {
        avgPsWaiting += process.waitingTime;
        avgPsTurnaround += process.turnaroundTime;
    }
    avgPsWaiting /= n;
    avgPsTurnaround /= n;

    // Round Robin
    int timeQuantum;
    cout << "\nEnter Time Quantum for Round Robin: ";
    cin >> timeQuantum;
    roundRobin(rrProcesses, timeQuantum);
    float avgRrWaiting = 0, avgRrTurnaround = 0;
    for (const auto &process : rrProcesses)
    {
        avgRrWaiting += process.waitingTime;
        avgRrTurnaround += process.turnaroundTime;
    }
    avgRrWaiting /= n;
    avgRrTurnaround /= n;

    cout << "\n======================== Algorithm Comparison ========================\n";
    cout << left << setw(20) << "Algorithm" 
        << setw(25) << "Average Waiting Time" 
        << setw(25) << "Average Turnaround Time" << "\n";
    cout << "----------------------------------------------------------------------\n";
    cout << setw(20) << "FCFS" 
        << setw(25) << avgFcfsWaiting 
        << setw(25) << avgFcfsTurnaround << "\n";
    cout << setw(20) << "SJF" 
        << setw(25) << avgSjfWaiting 
        << setw(25) << avgSjfTurnaround << "\n";
    cout << setw(20) << "Priority" 
        << setw(25) << avgPsWaiting 
        << setw(25) << avgPsTurnaround << "\n";
    cout << setw(20) << "Round Robin" 
        << setw(25) << avgRrWaiting 
        << setw(25) << avgRrTurnaround << "\n";
    cout << "======================================================================\n";


    // Determine Best Algorithm
    float minAvgWaiting = min({avgFcfsWaiting, avgSjfWaiting, avgPsWaiting, avgRrWaiting});
    cout << "\nBest Algorithm based on Waiting Time: ";
    if (minAvgWaiting == avgFcfsWaiting)
        cout << "FCFS";
    else if (minAvgWaiting == avgSjfWaiting)
        cout << "SJF";
    else if (minAvgWaiting == avgPsWaiting)
        cout << "Priority Scheduling";
    else
        cout << "Round Robin";

    cout << "\n";

    float minAvgTurnaround = min({avgFcfsTurnaround, avgSjfTurnaround, avgPsTurnaround, avgRrTurnaround});
    cout << "Best Algorithm based on Turnaround Time: ";
    if (minAvgTurnaround == avgFcfsTurnaround)
        cout << "FCFS" << endl;
    else if (minAvgTurnaround == avgSjfTurnaround)
        cout << "SJF" << endl;
    else if (minAvgTurnaround == avgPsTurnaround)
        cout << "Priority Scheduling" << endl;
    else
        cout << "Round Robin" << endl;

    cout << "\n";
}
