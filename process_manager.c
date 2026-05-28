#include <stdio.h>
#include <string.h>
#include "include/eduos.h"

// ================= GLOBAL PROCESS TABLE =================
PCB process_table[MAX_PROCESSES];
int process_count = 0;
static int global_time = 0;

// ================= EXTERNAL GANTT (FROM scheduler.c) =================
extern int gantt_log[1000];
extern int gantt_index;

// ================= STATE CONVERTER =================
const char* state_to_string(ProcessState state) {
    switch(state) {
        case READY: return "READY";
        case RUNNING: return "RUNNING";
        case WAITING: return "WAITING";
        case TERMINATED: return "TERMINATED";
        default: return "UNKNOWN";
    }
}

// ================= SAVE JSON =================
void save_pcb_to_json() {
    FILE *file = fopen("pcb_snapshot.json", "w");
    if (!file) return;

    fprintf(file, "[\n");

    for (int i = 0; i < process_count; i++) {
        PCB *p = &process_table[i];

        fprintf(file,
            "  {\"pid\": %d, \"name\": \"%s\", \"state\": \"%s\", "
            "\"priority\": %d, \"burst_time\": %d, "
            "\"remaining_time\": %d, \"waiting_time\": %d, \"turnaround_time\": %d}%s\n",
            p->pid,
            p->name,
            state_to_string(p->state),
            p->priority,
            p->burst_time,
            p->remaining_time,
            p->waiting_time,
            p->turnaround_time,
            (i == process_count - 1) ? "" : ","
        );
    }

    fprintf(file, "]\n");
    fclose(file);
}

// ================= CREATE PROCESS =================
void create_process(const char *name, int priority, int burst_time) {

    PCB *p = &process_table[process_count];

    p->pid = process_count + 1;
    strcpy(p->name, name);

    p->priority = priority;
    p->burst_time = burst_time;

    p->remaining_time = burst_time;
    p->arrival_time = global_time;

    p->state = READY;

    process_count++;

    printf("Process created: %s (PID=%d)\n", name, p->pid);

    save_pcb_to_json();
}

// ================= DISPLAY =================
void display_processes() {

    printf("\n===== PROCESS TABLE =====\n");

    for (int i = 0; i < process_count; i++) {

        PCB *p = &process_table[i];

        printf("PID:%d | %s | %d | Burst:%d | Remaining:%d | WT:%d | TAT:%d\n",
            p->pid,
            p->name,
            p->priority,
            p->burst_time,
            p->remaining_time,
            p->waiting_time,
            p->turnaround_time
        );
    }
}

// ================= RUN PROCESS =================
void run_process(int pid) {

    for (int i = 0; i < process_count; i++) {

        PCB *p = &process_table[i];

        if (p->pid == pid && p->remaining_time > 0) {

            p->state = RUNNING;

            printf("Running PID %d (%s)\n", p->pid, p->name);

            p->remaining_time--;
            global_time++;

            gantt_log[gantt_index++] = pid;

            if (p->remaining_time == 0) {
                p->state = TERMINATED;
            }

            save_pcb_to_json();
            return;
        }
    }
}