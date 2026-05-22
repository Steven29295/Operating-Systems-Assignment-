#include <stdio.h>
#include <string.h>
#include "include/eduos.h"

#define MAX_PROCESSES 10

PCB processes[MAX_PROCESSES];
int process_count = 0;

// Create process
void create_process(int pid, const char *name) {

    if (process_count >= MAX_PROCESSES) {
        printf("Process limit reached!\n");
        return;
    }

    processes[process_count].pid = pid;

    strcpy(processes[process_count].name, name);

    processes[process_count].state = READY;

    process_count++;

    printf("Process created: %s (PID: %d)\n", name, pid);
}

// Display all processes
void display_processes() {

    printf("\nProcess List:\n");

    for (int i = 0; i < process_count; i++) {

        printf("PID: %d | Name: %s | State: %d\n",
               processes[i].pid,
               processes[i].name,
               processes[i].state);
    }
}

// Run a process
void run_process(int pid) {

    for (int i = 0; i < process_count; i++) {

        if (processes[i].pid == pid) {

            processes[i].state = RUNNING;

            printf("Process %s is now RUNNING\n",
                   processes[i].name);

            return;
        }
    }

    printf("Process not found!\n");
}

// Terminate a process
void terminate_process(int pid) {

    for (int i = 0; i < process_count; i++) {

        if (processes[i].pid == pid) {

            processes[i].state = TERMINATED;

            printf("Process %s TERMINATED\n",
                   processes[i].name);

            return;
        }
    }

    printf("Process not found!\n");

}
