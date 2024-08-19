# CPU Scheduling Visualiser

The CPU Scheduling application is a tool used to visualize various CPU scheduling algorithms. The application calculates metrics like average waiting time and average turnaround time
and presents the results in an easy-to-understand tabular format.

## Features

- Three Scheduling Algorithms are implemented:
  - FCFS (First-Come, First-Served)
  - SJF (Shortest Job First)
  - Round Robin (with custom time quantum)
- User Input:
  - Arrival time, burst time, and priority for each process.
- Output:
  - Start time, completion time, and waiting time for each process.
  - Average waiting time and average turnaround time.
 
## Usage

1. Clone the repository.
```
git clone https://github.com/AmeyPPatil/CPU-Scheduling-Visualiser.git
cd cpu-scheduling-visualizer
```

2. Install Node.js and Express.
```
npm install express
```

3. Compile the C++ Code.
Make sure you're in the scheduling_algorithms directory, and run the following command:
```
g++ -std=c++11 -Iinclude -o scheduler main.cpp first_come_first_serve.cpp shortest_job_first.cpp round_robin.cpp
```

4. After compiling, run the program. You will be prompted to enter the arrival time, burst time, and priority for each process. Input this data to generate the results.
```
./scheduler
```

5. Start the Express server from the main directory to view the results.
```
node server.js
```
6. Open your web browser and navigate to http://localhost:3000 to view the scheduling results in a tabular format.
