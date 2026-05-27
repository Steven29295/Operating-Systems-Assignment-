#ifndef EDUOS_H
#define EDUOS_H

#define MAX_PROCESSES 10
#define MAX_THREADS 20

// Process states
typedef enum {
    READY,
    RUNNING,
    WAITING,
    TERMINATED
} ProcessState;

// Process Control Block (PCB)
typedef struct {
    int pid;
    char name[50];
    ProcessState state;
    int priority;
    int burst_time;
    int owner_id;
} PCB;

// Thread Control Block (TCB)
typedef struct {
    int tid;
    int parent_pid;
    char name[50];
} TCB;

// ================= PROCESS FUNCTIONS =================

void create_process(const char *name, int priority, int burst_time);
void display_processes();

void run_process(int pid);
void terminate_process(int pid);

void save_pcb_to_json();

// ================= THREAD FUNCTIONS =================

void create_thread(int tid, int parent_pid, const char *name);
void display_threads();

void run_race_demo();

void scheduler();


#endif
