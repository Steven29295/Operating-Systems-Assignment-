#include <stdio.h>
#include "scheduler.h"

void fcfs(Process p[], int n)
{
    int total_waiting = 0;
    int total_turnaround = 0;

    p[0].waiting_time = 0;

    for(int i = 1; i < n; i++)
    {
        p[i].waiting_time =
            p[i-1].waiting_time +
            p[i-1].burst_time;
    }

    for(int i = 0; i < n; i++)
    {
        p[i].turnaround_time =
            p[i].waiting_time +
            p[i].burst_time;

        total_waiting += p[i].waiting_time;
        total_turnaround += p[i].turnaround_time;

        printf(
            "P%d | Burst=%d | Waiting=%d | Turnaround=%d\n",
            p[i].pid,
            p[i].burst_time,
            p[i].waiting_time,
            p[i].turnaround_time
        );
    }

    printf("\nAverage Waiting Time: %.2f\n",
        (float)total_waiting / n);

    printf("Average Turnaround Time: %.2f\n",
        (float)total_turnaround / n);
}