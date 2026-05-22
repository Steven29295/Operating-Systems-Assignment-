#include <stdio.h>
#include "eduos.h"

// Create a process
PCB create_process(int pid, int priority) {
    PCB p;

    p.pid = pid;
    p.priority = priority;
    p.state = READY;

    printf("Process %d created (READY)\n", p.pid);

    return p;
}