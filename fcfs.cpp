#include "scheduling.h"

bool sortByArrivalTime(const Process &a, const Process &b)
{
    return a.arrivalTime < b.arrivalTime;
}

void firtComeFirstSeerved(vector<Process>&processes)
{
    int n = processes.size();
    
    sort(processes.begin(), processes.end(), sortByArrivalTime);

    int currentTime = 0;

    for (int i = 0; i < n; i++)
    {
        if(currentTime < processes[i].arrivalTime)
        {
            currentTime = processes[i].arrivalTime;
        }

        processes[i].completionTime = currentTime+processes[i].burstTime;
        processes[i].turnAroundTime = processes[i].completionTime-processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnAroundTime-processes[i].burstTime;
        currentTime = processes[i].completionTime;
    }
    
    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n";
    for (const auto& process : processes) {
        cout << "P" << process.id << "\t" 
             << process.arrivalTime << "\t\t" 
             << process.burstTime << "\t\t" 
             << process.waitingTime << "\t\t" 
             << process.turnAroundTime << "\t\t" 
             << process.completionTime << "\n";
    }

    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (const auto& process:processes)
    {
        totalWaitingTime+=process.waitingTime;
        totalTurnaroundTime+=process.turnAroundTime;
    }

    cout << fixed << setprecision(2);

    cout << "\nAverage Waiting Time: " << totalWaitingTime / n << "\n";
    cout << "Average Turnaround Time: " << totalTurnaroundTime / n << "\n";

    cout << "\nGantt Chart:\n";
    cout << "|";
    for (const auto& process : processes) {
        cout << " P" << process.id << " |";
    }
    cout << "\n0";
    for (const auto& process : processes) {
        cout << setw(5) << process.completionTime;
    }
    cout << "\n";
}
