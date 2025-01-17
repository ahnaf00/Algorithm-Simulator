#include "scheduling.h"

void calculatePriorityScheduling(vector<ProcessPS>&processes)
{
    int n = processes.size();
    int completed = 0, currentTime = 0, minIndex = -1;
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (auto &p:processes)
    {
        p.remainingTime = p.burstTime;
    }

    vector<int> gantChart;

    while (completed < n)
    {
        int highestPriority = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if(processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0 && processes[i].priority < highestPriority)
            {
                highestPriority = processes[i].priority;
                minIndex = i;
            }
        }

        if(minIndex == -1)
        {
            if (gantChart.empty() || gantChart.back() != -1) {
                gantChart.push_back(-1); // Add idle only once
            }
            currentTime++;
            continue;
        }

        if (gantChart.empty() || gantChart.back() != processes[minIndex].id) {
            gantChart.push_back(processes[minIndex].id); // Add process ID when it starts execution
        }

        processes[minIndex].remainingTime--;
        currentTime++;

        if(processes[minIndex].remainingTime == 0)
        {
            completed++;
            processes[minIndex].completionTime = currentTime;
            processes[minIndex].turnaroundTime = processes[minIndex].completionTime - processes[minIndex].arrivalTime;
            processes[minIndex].waitingTime = processes[minIndex].turnaroundTime-processes[minIndex].burstTime;

            totalTurnaroundTime += processes[minIndex].turnaroundTime;
            totalWaitingTime += processes[minIndex].waitingTime;
        }
        
    }
    

    cout << "\nProcess\tAT\tBT\tPri\tCT\tTAT\tWT\n";
    for (auto& p : processes) {
        cout << "P" << p.id << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t"
             << p.priority << "\t" << p.completionTime << "\t" << p.turnaroundTime << "\t" << p.waitingTime << "\n";
    }

    cout << "\nAverate Turnaround Time : " << (float)totalTurnaroundTime / n << endl;
    cout << "\nAverage Waiting Time : " << (float) totalWaitingTime / n << endl;

    cout << "\nGant Chart: \n";
    for (int i = 0; i < gantChart.size(); i++)
    {
        if(gantChart[i] == -1)
        {
            cout << "Idle ";
        }
        else
        {
            cout << "P" <<  gantChart[i] << " ";
        }
    }

    cout << endl;
}
