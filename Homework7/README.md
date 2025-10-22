FCFS_SJF Scheduler
==================

This directory contains `FCFS_SJF.c`, a simple process scheduling simulator implementing:

- First Come First Served (FCFS)
- Shortest Job First (SJF) — non-preemptive (global burst-time ordering)

The program prompts the user for the number of processes and then for each process' arrival time and burst time. It prints the Gantt chart, per-process metrics (WT, TAT, RT), and averages for each scheduling algorithm.

Compile
-------

Use gcc to compile the program:

```bash
gcc -std=c11 -Wall -Wextra -O2 -o FCFS_SJF FCFS_SJF.c
```

Run
---

Run the program and follow prompts. Example interactive session using the sample from the assignment:

```text
$ ./FCFS_SJF
Enter the number of processes: 4
Enter the arrival time and burst time for process 1: 0 8
Enter the arrival time and burst time for process 2: 1 4
Enter the arrival time and burst time for process 3: 2 9
Enter the arrival time and burst time for process 4: 3 5
```

The program will print the FCFS and SJF scheduling results including Gantt charts and average metrics.

