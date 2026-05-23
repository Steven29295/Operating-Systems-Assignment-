#ifndef EDUOS_H
#define EDUOS_H

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
} PCB;

// Thread Control Block (TCB)
typedef struct {
    int tid;
    int parent_pid;
    char name[50];
} TCB;

// Function declarations
void create_process(int pid, const char *name);
void display_processes();

void run_process(int pid);
void terminate_process(int pid);

void create_thread(int tid, int parent_pid, const char *name);
void display_threads();

void scheduler();

#endif
