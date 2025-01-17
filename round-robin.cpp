#include "scheduling.h"

void roundRobin(vector<ProcessRR> &processes, int timeQuantum) {
    int n = processes.size();
    queue<int> readyQueue;

    for (int i = 0; i < n; i++) {
        processes[i].remainingTime = processes[i].burstTime;
        readyQueue.push(i);
    }

    int currentTime = 0;

    while (!readyQueue.empty()) {
        int index = readyQueue.front();
        readyQueue.pop();

        // ProcessRR the current process for a time quantum or its remaining time
        int timeSlice = min(timeQuantum, processes[index].remainingTime);
        currentTime += timeSlice;
        processes[index].remainingTime -= timeSlice;

        if (processes[index].remainingTime > 0) {
            readyQueue.push(index); // Re-add process to the queue if it's not finished
        } else {
            // Calculate completion, turnaround, and waiting times
            processes[index].completionTime = currentTime;
            processes[index].turnaroundTime = processes[index].completionTime - processes[index].arrivalTime;
            processes[index].waitingTime = processes[index].turnaroundTime - processes[index].burstTime;
        }
    }

    cout << "PID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for (const auto &process : processes) {
        cout << process.pid << "\t" << process.arrivalTime << "\t\t" << process.burstTime << "\t\t"
             << process.completionTime << "\t\t" << process.waitingTime << "\t\t" << process.turnaroundTime << "\n";
    }

    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;

    for (const auto &process : processes) {
        totalWaitingTime += process.waitingTime;
        totalTurnaroundTime += process.turnaroundTime;
    }

    cout << "\nAverage Waiting Time: " << fixed << setprecision(2) << totalWaitingTime / processes.size() << endl;
    cout << "Average Turnaround Time: " << fixed << setprecision(2) << totalTurnaroundTime / processes.size() << endl;
}
