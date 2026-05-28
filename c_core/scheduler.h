#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef struct {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
}Process;

void fcfs(Process p[], int n);

#endif