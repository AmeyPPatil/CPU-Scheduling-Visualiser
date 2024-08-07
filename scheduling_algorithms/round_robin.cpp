#include <vector>
#include <algorithm>
#include <queue>
#include "algorithms.h"

using namespace std;

void round_robin_algorithm(vector<Process>& processes, int time_quantum) {
    int current_time = 0;
    int n = processes.size();

    vector<int> time_remaining(n);
    queue<int> process_queue;

    // initialize the time remaining for each process and the process queue
    for (int i = 0; i < n; i++) {
        time_remaining[i] = processes[i].burst_time;
    }

    for (int i = 0; i < n; i++) {
        process_queue.push(i);
    }

    while (!process_queue.empty()) {

        int i = process_queue.front();
        process_queue.pop();

        // calculate start and completion times
        if (time_remaining[i] > time_quantum) {
            if (processes[i].start_time == -1) processes[i].start_time = current_time;
            current_time += time_quantum;
            time_remaining[i] -= time_quantum;
            process_queue.push(i);
        }
        else {
            if (processes[i].start_time == -1) processes[i].start_time = current_time;
            current_time += time_remaining[i];
            processes[i].completion_time = current_time;
            processes[i].waiting_time = processes[i].start_time - processes[i].arrival_time;
            processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
            time_remaining[i] = 0;
        }
    }
}
