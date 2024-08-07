#include <vector>
#include <algorithm>
#include "algorithms.h"

using namespace std;

void fcfs_algorithm(vector<Process>& processes) {
    int current_time = 0;

    // sort processes by arrival time
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arrival_time < b.arrival_time;
    });

    
    for (auto &process : processes) {
        if (process.arrival_time > current_time) {
            current_time = process.arrival_time;
        }
        process.start_time = current_time;
        current_time += process.burst_time;
        process.completion_time = current_time;
        process.waiting_time = process.start_time - process.arrival_time;
        process.turnaround_time = process.completion_time - process.arrival_time;
    }
}
