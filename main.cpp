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
            break;
        }
    }
    

    return 0;
}