#include <stdio.h>
#include <string.h>
#include "include/eduos.h"

PCB process_table[MAX_PROCESSES];
int process_count = 0;

// Convert state enum to string
const char* state_to_string(ProcessState state) {

    switch(state) {

        case READY:
            return "READY";

        case RUNNING:
            return "RUNNING";

        case WAITING:
            return "WAITING";

        case TERMINATED:
            return "TERMINATED";

        default:
            return "UNKNOWN";
    }
}

// Save PCB snapshot to JSON
void save_pcb_to_json() {

    FILE *file = fopen("pcb_snapshot.json", "w");

    if(file == NULL) {
        printf("Failed to create JSON file.\n");
        return;
    }

    fprintf(file, "[\n");

    for(int i = 0; i < process_count; i++) {

        fprintf(file,
            "  {\n"
            "    \"pid\": %d,\n"
            "    \"name\": \"%s\",\n"
            "    \"state\": \"%s\",\n"
            "    \"priority\": %d,\n"
            "    \"burst_time\": %d\n"
            "  }%s\n",

            process_table[i].pid,
            process_table[i].name,
            state_to_string(process_table[i].state),
            process_table[i].priority,
            process_table[i].burst_time,

            (i == process_count - 1) ? "" : ","
        );
    }

    fprintf(file, "]\n");

    fclose(file);

    printf("PCB snapshot saved.\n");
}

// Create process
void create_process(const char *name, int priority, int burst_time) {

    PCB new_process;

    new_process.pid = process_count + 1;

    strcpy(new_process.name, name);

    new_process.state = READY;

    new_process.priority = priority;

    new_process.burst_time = burst_time;

    process_table[process_count] = new_process;

    process_count++;

    printf("Process created: %s\n", name);

    save_pcb_to_json();
}

// Display processes
void display_processes() {

    printf("\n===== PROCESS TABLE =====\n");

    for(int i = 0; i < process_count; i++) {

        printf(
            "PID: %d | Name: %s | State: %s | Priority: %d | Burst: %d\n",

            process_table[i].pid,
            process_table[i].name,
            state_to_string(process_table[i].state),
            process_table[i].priority,
            process_table[i].burst_time
        );
    }
}

// Run process
void run_process(int pid) {

    for(int i = 0; i < process_count; i++) {

        if(process_table[i].pid == pid) {

            process_table[i].state = RUNNING;

            printf("Process %d is RUNNING\n", pid);

            save_pcb_to_json();

            return;
        }
    }
}

// Terminate process
void terminate_process(int pid) {

    for(int i = 0; i < process_count; i++) {

        if(process_table[i].pid == pid) {

            process_table[i].state = TERMINATED;

            printf("Process %d TERMINATED\n", pid);

            save_pcb_to_json();

            return;
        }
    }
}

// Simple FCFS Scheduler
void scheduler() {

    printf("\nRunning FCFS Scheduler...\n");

    for(int i = 0; i < process_count; i++) {

        run_process(process_table[i].pid);

        terminate_process(process_table[i].pid);
    }
}