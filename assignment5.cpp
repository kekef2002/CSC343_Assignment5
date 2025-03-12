/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id, burstTime, waitingTime, turnaroundTime;
};

// Function to calculate turnaround and waiting time for FCFS
void calculateFCFS(vector<Process>& processes) {
    int totalWaiting = 0, totalTurnaround = 0;
    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;

    for (size_t i = 1; i < processes.size(); i++) {
        processes[i].waitingTime = processes[i-1].waitingTime + processes[i-1].burstTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }

    cout << "----------------- FCFS -----------------" << endl;
    cout << "Process ID | Waiting Time | Turnaround Time\n";
    for (auto& p : processes) {
        totalWaiting += p.waitingTime;
        totalTurnaround += p.turnaroundTime;
        cout << "     " << p.id << "      |      " << p.waitingTime << "        |        " << p.turnaroundTime << endl;
    }
    cout << "Average Waiting Time: " << (float)totalWaiting / processes.size() << endl;
    cout << "Average Turnaround Time: " << (float)totalTurnaround / processes.size() << endl;
}

// Function to calculate turnaround and waiting time for SJF
void calculateSJF(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.burstTime < b.burstTime;
    });

    calculateFCFS(processes);  // SJF behaves like FCFS after sorting
}

int main() {
    vector<Process> processes = {
        {1, 2, 0, 0},
        {2, 1, 0, 0},
        {3, 8, 0, 0},
        {4, 4, 0, 0},
        {5, 5, 0, 0}
    };

    calculateFCFS(processes);
    calculateSJF(processes);

    return 0;
}
