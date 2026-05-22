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

// Function declarations
void create_process(int pid, const char *name);
void display_processes();

void run_process(int pid);
void terminate_process(int pid);

#endif