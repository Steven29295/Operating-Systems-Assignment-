#include <stdio.h>
#include "eduos.h"

PCB create_process(int pid, int priority);

int main() {
    printf("OS Simulation starting...\n");

    PCB p1 = create_process(1, 5);
    PCB p2 = create_process(2, 3);

    return 0;
}
