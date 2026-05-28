#include <stdio.h>
#include "include/eduos.h"

// ================= EXTERNAL PROCESS TABLE =================
extern PCB process_table[MAX_PROCESSES];
extern int process_count;

// ================= GANTT STORAGE (ONLY HERE) =================
int gantt_log[1000];
int gantt_index = 0;

// ================= ADD TO GANTT =================
void add_gantt(int pid) {
    gantt_log[gantt_index++] = pid;
}

// ================= FCFS =================
void scheduler() {

    printf("\n=== FCFS SCHEDULER ===\n");

    for (int i = 0; i < process_count; i++) {
        while (process_table[i].remaining_time > 0) {
            run_process(process_table[i].pid);
        }
    }
}

// ================= ROUND ROBIN =================
void scheduler_rr() {

    printf("\n=== ROUND ROBIN ===\n");

    int quantum = 2;
    int done;

    do {
        done = 1;

        for (int i = 0; i < process_count; i++) {

            if (process_table[i].remaining_time > 0) {

                done = 0;

                int exec = (process_table[i].remaining_time > quantum)
                            ? quantum
                            : process_table[i].remaining_time;

                for (int j = 0; j < exec; j++) {
                    run_process(process_table[i].pid);
                }
            }
        }

    } while (!done);
}

// ================= PRIORITY =================
void scheduler_priority() {

    printf("\n=== PRIORITY SCHEDULER ===\n");

    for (int i = 0; i < process_count - 1; i++) {
        for (int j = i + 1; j < process_count; j++) {

            if (process_table[j].priority < process_table[i].priority) {

                PCB temp = process_table[i];
                process_table[i] = process_table[j];
                process_table[j] = temp;
            }
        }
    }

    scheduler();
}

// ================= CPU UTILIZATION =================
void cpu_utilization() {

    int busy = 0;

    for (int i = 0; i < process_count; i++) {
        busy += process_table[i].burst_time;
    }

    printf("\n=== CPU UTILIZATION ===\n");
    printf("Busy Time: %d\n", busy);
}

// ================= GANTT CHART =================
void print_gantt_chart() {

    printf("\n=== GANTT CHART ===\n");

    for (int i = 0; i < gantt_index; i++) {
        printf("| P%d ", gantt_log[i]);
    }

    printf("|\n");
}