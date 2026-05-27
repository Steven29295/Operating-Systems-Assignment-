#include <stdio.h>
#include "include/eduos.h"
#include "scheduler.h"

int main() {

    // Create processes
    create_process("Chrome", 1, 5);
    create_process("VSCode", 2, 3);

    // Create threads
    create_thread(101, 1, "Chrome Renderer");
    create_thread(102, 1, "Chrome GPU");
    create_thread(201, 2, "VSCode Extension Host");

    // Run scheduler
    scheduler();

    // Display all processes
    display_processes();

    // Display all threads
    display_threads();
    
 Process p[3] = {
        {1, 5, 0, 0},
        {2, 3, 0, 0},
        {3, 8, 0, 0}
    };

    printf("\n=== FCFS Scheduling ===\n");

    fcfs(p, 3);

    return 0;
}