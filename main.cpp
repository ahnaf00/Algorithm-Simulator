#include "scheduling.h"


int main()
{
    while (true)
    {
        int num;
        cout << "1. First Come First Serve (FCFS)\n2.Shortest Job First(SJF)\n3. Terminate\nSelect Algorithm : ";
        cin >> num;

        if(num==1)
        {
            int n;
            cout << "Enter number of processes :" << endl;
            cin >> n;

            vector<Process> processes(n);

            for (int i = 0; i < n; i++)
            {
                processes[i].id = i+1;
                cout << "Enter the arrival time for Process " << i+1 << ": ";
                cin >> processes[i].arrivalTime;
                cout << "Enter the burst time for the Process : ";
                cin >> processes[i].burstTime;
            }
            firtComeFirstSeerved(processes);
        }
        else if(num==2)
        {
            int n;
            cout << "Enter the number of process: " ;
            cin >> n;

            vector<ProcessSJF> processes(n);

            for (int i = 0; i < n; i++)
            {
                processes[i].id = i+1;
                cout << "Enter the arrival time for Process " << i+1 << ": ";
                cin >> processes[i].arrivalTime;
                cout << "Enter the burst time for the process : ";
                cin >> processes[i].burstTime;
            }

            calculateSJF(processes);
        }
        else if (num == 3)
        {
            int n; 
            cout << "Enter the number of processes: ";
            cin >> n;

            vector<ProcessPS> processes(n);

            cout << "Enter the Arrival Time, Burts Time and Priority for each process:" << endl;

            for (int i = 0; i < n; i++)
            {
                processes[i].id = i+1;
                cout << "Process " << i+1 << ":" << endl;

                cout << "Arrival Time : ";
                cin >> processes[i].arrivalTime;

                cout << "Burst Time : ";
                cin >> processes[i].burstTime;

                cout << "Priority : ";
                cin >> processes[i].priority;
            }

            calculatePriorityScheduling(processes);
        }

        else if(num == 4)
        {
            int n, timeQuantum;

            cout << "Enter the number of processes: ";
            cin >> n;

            cout << "Enter the time quantum: ";
            cin >> timeQuantum;

            vector<ProcessRR> processes(n);

            for (int i = 0; i < n; i++) {
                cout << "Enter arrival time for process " << i + 1 << ": ";
                cin >> processes[i].arrivalTime;
                cout << "Enter burst time for process " << i + 1 << ": ";
                cin >> processes[i].burstTime;
                processes[i].pid = i + 1;
                processes[i].waitingTime = 0;
                processes[i].turnaroundTime = 0;
                processes[i].completionTime = 0;
            }

            roundRobin(processes, timeQuantum);
        }
    }
    

    return 0;
}