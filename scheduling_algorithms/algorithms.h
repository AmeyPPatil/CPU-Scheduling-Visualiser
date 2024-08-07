#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>

using namespace std;

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

void fcfs_algorithm(vector<Process>& processes);
void sjf_algorithm(vector<Process>& processes);
void round_robin_algorithm(vector<Process>& processes, int time_quantum);

#endif
