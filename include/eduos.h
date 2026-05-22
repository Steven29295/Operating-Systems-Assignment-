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
    ProcessState state;
    int priority;
} PCB;

#endif