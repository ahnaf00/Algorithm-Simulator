#include "scheduling.h"

void roundRobin(vector<ProcessRR> &processes, int timeQuantum) {
    queue<int> readyQueue;
    vector<int> ganttChart; // Store Gantt chart sequence
    int currentTime = 0;
    int completed = 0;
    int n = processes.size();

    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), [](ProcessRR& a, ProcessRR& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    // Push the first process into the ready queue
    readyQueue.push(0);
    vector<bool> inQueue(n, false);
    inQueue[0] = true;

    while (completed < n) {
        if (readyQueue.empty()) {
            currentTime++;
            for (int i = 0; i < n; i++) {
                if (!inQueue[i] && processes[i].arrivalTime <= currentTime) {
                    readyQueue.push(i);
                    inQueue[i] = true;
                    break;
                }
            }
            continue;
        }

        int currentProcess = readyQueue.front();
        readyQueue.pop();

        if (processes[currentProcess].remainingTime > timeQuantum) {
            ganttChart.push_back(processes[currentProcess].pid);
            currentTime += timeQuantum;
            processes[currentProcess].remainingTime -= timeQuantum;

            // Add newly arrived processes to the ready queue
            for (int i = 0; i < n; i++) {
                if (!inQueue[i] && processes[i].arrivalTime <= currentTime) {
                    readyQueue.push(i);
                    inQueue[i] = true;
                }
            }

            // Re-add current process to the end of the queue
            readyQueue.push(currentProcess);
        } else {
            ganttChart.push_back(processes[currentProcess].pid);
            currentTime += processes[currentProcess].remainingTime;
            processes[currentProcess].remainingTime = 0;
            processes[currentProcess].completionTime = currentTime;
            processes[currentProcess].turnaroundTime = processes[currentProcess].completionTime - processes[currentProcess].arrivalTime;
            processes[currentProcess].waitingTime = processes[currentProcess].turnaroundTime - processes[currentProcess].burstTime;
            completed++;

            // Add newly arrived processes to the ready queue
            for (int i = 0; i < n; i++) {
                if (!inQueue[i] && processes[i].arrivalTime <= currentTime) {
                    readyQueue.push(i);
                    inQueue[i] = true;
                }
            }
        }
    }

    cout << "\nProcess	Arrival	Burst	Completion	Turnaround	Waiting" << endl;
    for (const auto& process : processes) {
        cout << "P" << process.pid << "\t"
            << process.arrivalTime << "\t"
            << process.burstTime << "\t"
            << process.completionTime << "\t\t"
            << process.turnaroundTime << "\t\t"
            << process.waitingTime << endl;
    }

    // Print Gantt chart
    cout << "\nGantt Chart: " << endl;
    for (int pid : ganttChart) {
        cout << "| P" << pid << " ";
    }
    cout << "|" << endl;
}