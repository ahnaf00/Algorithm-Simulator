#include "scheduling.h"

// class Process{
//     public:
//         int id;
//         int arrivalTime;
//         int burstTime;
//         int remainingTime;
//         int completionTime;
//         int waitingTime;
//         int turnaroundTime;
// };

void calculateSJF(vector<ProcessSJF>&processes)
{
    int n = processes.size();
    int completed = 0, currentTime = 0, minIndex = -1;
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    for(auto &p : processes)
    {
        p.remainingTime = p.burstTime;
    }

    while (completed < n)
    {
        int minRemainingTime = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if(processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0 && processes[i].remainingTime < minRemainingTime)
            {
                minRemainingTime = processes[i].remainingTime;
                minIndex = i;
            }
        }

        if(minIndex == -1)
        {
            currentTime++;
            continue;
        }

        processes[minIndex].remainingTime--;
        currentTime++;

        if(processes[minIndex].remainingTime == 0)
        {
            completed++;
            processes[minIndex].completionTime = currentTime;
            processes[minIndex].turnaroundTime = processes[minIndex].completionTime - processes[minIndex].arrivalTime;
            processes[minIndex].waitingTime = processes[minIndex].turnaroundTime-processes[minIndex].burstTime;

            totalWaitingTime += processes[minIndex].waitingTime;
            totalTurnaroundTime += processes[minIndex].turnaroundTime;
        }
    }

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto& p : processes) {
        cout << "P" << p.id << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t"
             << p.completionTime << "\t" << p.turnaroundTime << "\t" << p.waitingTime << "\n";
    }

    cout << "\nAverage Turnaround Time: " << (float)totalTurnaroundTime / n << "\n";
    cout << "Average Waiting Time: " << (float)totalWaitingTime / n << "\n";
    
}

// int main()
// {
//     int n;
//     cout << "Enter the number of process: " ;
//     cin >> n;

//     vector<Process> processes(n);

//     for (int i = 0; i < n; i++)
//     {
//         processes[i].id = i+1;
//         cout << "Enter the arrival time for Process " << i+1 << ": ";
//         cin >> processes[i].arrivalTime;
//         cout << "Enter the burst time for the process : ";
//         cin >> processes[i].burstTime;
//     }
    
//     calculateSJF(processes);

//     return 0;
// }