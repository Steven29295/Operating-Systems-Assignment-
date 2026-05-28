#include <stdio.h>
#include "include/eduos.h"

int main() {

    printf("=== EduOS Simulator ===\n\n");

    // Create processes
    create_process("Chrome", 1, 5);
    create_process("VSCode", 2, 3);

    // Create threads
    create_thread(101, 1, "Chrome Renderer");
    create_thread(102, 1, "Chrome GPU");
    create_thread(201, 2, "VSCode Extension Host");

    // Display processes
    display_processes();

    // Display threads
    display_threads();

    // FCFS Scheduling
    printf("\n=== FCFS Scheduling ===\n");
    scheduler();

    // Race condition demo
    printf("\n=== Race Condition Demo ===\n");
    run_race_demo();

    return 0;
}