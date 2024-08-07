#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "algorithms.h"

using namespace std;

/*  
    the Process struct:
    struct Process {
        int number;
        int arrival_time;
        int burst_time;
        int priority;
        int start_time;
        int completion_time;
        int waiting_time;
        int turnaround_time;
    };
*/

// Functions to calculate the required parameters according to the specified algorithm
void fcfs_algorithm(vector<Process>& processes);
void sjf_algorithm(vector<Process>& processes);
void round_robin_algorithm(vector<Process>& processes, int time_quantum);

// Function to write the calculated parameters in the output file
void write_results(string &algorithm, vector<Process> &processes);

int main() {
    vector<Process> processes;
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Process p;
        cout << "Enter process number: ";
        cin >> p.number;
        cout << "Enter arrival time: ";
        cin >> p.arrival_time;
        cout << "Enter burst time: ";
        cin >> p.burst_time;
        cout << "Enter priority: ";
        cin >> p.priority;
        p.start_time = -1;
        p.completion_time = -1;
        p.waiting_time = -1;
        p.turnaround_time = -1;
        processes.push_back(p);
    }

    string algorithm;
    cout << "Select a scheduling algorithm (fcfs / sjf / rr): ";
    cin >> algorithm;

    if (algorithm == "fcfs") {
        fcfs_algorithm(processes);
    }
    else if (algorithm == "sjf") {
        sjf_algorithm(processes);
    }
    else if (algorithm == "rr") {
        int time_quantum;
        cout << "Enter time quantum for Round Robin: ";
        cin >> time_quantum;
        round_robin_algorithm(processes, time_quantum);
    }
    else {
        cerr << "Invalid algorithm selected." << endl;
        return 1;
    }

    write_results(algorithm, processes);

    return 0;
}

void write_results(string &algorithm, vector<Process> &processes) {
    int n = processes.size();
    int total_wait = 0;
    int total_turnaround = 0;
    string name = "";
    if (algorithm == "fcfs") {
        name = "First Come First Serve";
    }
    else if (algorithm == "sjf") {
        name = "Shortest Job First";
    }
    else if (algorithm == "rr") {
        name = "Round Robin";
    }

    ofstream file("../public/output.txt");
    if (file.is_open()) {
        file << "Scheduling Algorithm: " + name << endl;
        file << "Process Number," << "Arrival Time," << "Burst Time," << "Priority," << "Start Time," "Completion Time," << "Waiting Time," << "Turnaround Time" << endl;

        for (int i = 0; i < n; i++)
        {
            total_wait += processes[i].waiting_time;
            total_turnaround += processes[i].turnaround_time;
            file << processes[i].number << ',' << processes[i].arrival_time << ',' << processes[i].burst_time << ',' << processes[i].priority << ',' << processes[i].start_time << ',' << processes[i].completion_time << ',' << processes[i].waiting_time << ',' << processes[i].turnaround_time << endl;
        }

        file << "Average Waiting Time: " << (float)total_wait / n << endl;
        file << "Average Turnaround Time: " << (float)total_turnaround / n << endl;

        file.close();
    }
}
