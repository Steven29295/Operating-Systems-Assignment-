#include <stdio.h>
#include <string.h>
#include "eduos.h"

#define MAX_PROCESSES 10

static PCB process_table[MAX_PROCESSES];
static int process_count = 0;

void create_process(int pid, const char *name) {
    if (process_count >= MAX_PROCESSES) {
        printf("Process table full!\n");
        return;
    }

    process_table[process_count].pid = pid;
    strcpy(process_table[process_count].name, name);
    process_table[process_count].state = READY;

    process_count++;

    printf("Process %s (PID=%d) created.\n", name, pid);
}

void display_processes() {
    printf("\n--- Process Table ---\n");
    for (int i = 0; i < process_count; i++) {
        printf("PID: %d | Name: %s | State: %d\n",
               process_table[i].pid,
               process_table[i].name,
               process_table[i].state);
    }
}

void run_process(int pid) {
    for (int i = 0; i < process_count; i++) {
        if (process_table[i].pid == pid) {
            process_table[i].state = RUNNING;
            printf("Process %d is RUNNING\n", pid);
            return;
        }
    }
}

void terminate_process(int pid) {
    for (int i = 0; i < process_count; i++) {
        if (process_table[i].pid == pid) {
            process_table[i].state = TERMINATED;
            printf("Process %d TERMINATED\n", pid);
            return;
        }
    }
}
void scheduler() {
    printf("\n--- FCFS Scheduler ---\n");

    for (int i = 0; i < process_count; i++) {

        if (process_table[i].state == READY) {

            // simulate context switch
            process_table[i].state = RUNNING;

            printf("Running PID=%d | Name=%s\n",
                   process_table[i].pid,
                   process_table[i].name);

            // simulate process finishing CPU burst
            process_table[i].state = TERMINATED;
        }
    }
}