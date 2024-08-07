#include <vector>
#include <algorithm>
#include "algorithms.h"

using namespace std;

// custom comparator to sort processes by arrival time
bool compareArrival(Process a, Process b) {
    return a.arrival_time < b.arrival_time;
}

// custom comparator to sort processes by burst time
bool compareBurst(Process a, Process b) {
    return a.burst_time < b.burst_time;
}

void sjf_algorithm(vector<Process>& processes) {
    int current_time = 0;
    int n = processes.size();

    vector<int> completed(n, 0);
    int completed_processes = 0;

    while (completed_processes < n) {
        int job_index = -1;
        int job_burst_time = 1e9;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && processes[i].arrival_time <= current_time && processes[i].burst_time <= job_burst_time) {
                job_index = i;
                job_burst_time = processes[i].burst_time;
            }
        }

        if (job_index == -1) {
            current_time++;
            continue;
        }

        processes[job_index].start_time = current_time;
        current_time += processes[job_index].burst_time;
        processes[job_index].completion_time = current_time;
        processes[job_index].waiting_time = processes[job_index].start_time - processes[job_index].arrival_time;
        processes[job_index].turnaround_time = processes[job_index].completion_time - processes[job_index].arrival_time;

        completed[job_index] = true;
        completed_processes++;
    }
}

