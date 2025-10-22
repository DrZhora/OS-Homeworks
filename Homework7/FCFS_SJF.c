
#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
};

// Function to swap two processes
void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

// FCFS Scheduling
void fcfs(struct Process p[], int n) {
    
    int i, j;
    
    // Sort by arrival time
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (p[i].arrival_time > p[j].arrival_time)
                swap(&p[i], &p[j]);

    int current_time = 0;
    float total_wt = 0, total_tat = 0, total_rt = 0;

    printf("\n=== First Come First Served (FCFS) ===\n");
    printf("Gantt Chart: ");
    for (i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time)
            current_time = p[i].arrival_time;

        p[i].waiting_time = current_time - p[i].arrival_time;
        p[i].response_time = p[i].waiting_time;
        current_time += p[i].burst_time;
        p[i].turnaround_time = current_time - p[i].arrival_time;

        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
        total_rt += p[i].response_time;

        printf("| P%d ", p[i].pid);
    }
    printf("|\n");

    printf("\nPID\tAT\tBT\tWT\tTAT\tRT\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time,
               p[i].burst_time, p[i].waiting_time, p[i].turnaround_time, p[i].response_time);

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Response Time: %.2f\n", total_rt / n);
}


// SJF Scheduling (Non-preemptive)
void sjf(struct Process p[], int n) {
    
    int completed = 0, current_time = 0;
    float total_wt = 0, total_tat = 0, total_rt = 0;
    int is_completed[n];

    for (int i = 0; i < n; i++)
        is_completed[i] = 0;

    printf("\n=== Shortest Job First (SJF) ===\nGantt Chart: ");

    while (completed < n) {
        int idx = -1, min_bt = 1e9;

        for (int i = 0; i < n; i++)
            if (!is_completed[i] && p[i].arrival_time <= current_time)
                if (p[i].burst_time < min_bt || (p[i].burst_time == min_bt && p[i].arrival_time < p[idx].arrival_time))
                    idx = i, min_bt = p[i].burst_time;

        if (idx == -1) {
            // CPU idle
            int next_arrival = 1e9;
            for (int i = 0; i < n; i++)
                if (!is_completed[i] && p[i].arrival_time < next_arrival)
                    next_arrival = p[i].arrival_time;
            current_time = next_arrival;
            continue;
        }

        // Execute process
        printf("| P%d ", p[idx].pid);
        p[idx].waiting_time = current_time - p[idx].arrival_time;
        p[idx].response_time = p[idx].waiting_time;
        current_time += p[idx].burst_time;
        p[idx].turnaround_time = current_time - p[idx].arrival_time;

        is_completed[idx] = 1;
        completed++;

        total_wt += p[idx].waiting_time;
        total_tat += p[idx].turnaround_time;
        total_rt += p[idx].response_time;
    }
    printf("|\n");

    printf("\nPID\tAT\tBT\tWT\tTAT\tRT\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival_time, p[i].burst_time,
               p[i].waiting_time, p[i].turnaround_time, p[i].response_time);

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Response Time: %.2f\n", total_rt / n);
}



int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
    }

    fcfs(p, n);
    sjf(p, n);

    return 0;
}
