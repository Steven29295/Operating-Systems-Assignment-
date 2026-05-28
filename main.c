#include <stdio.h>
#include "include/eduos.h"
#include "scheduler.h"

// forward declarations
void fcfs_scheduler();
void scheduler_rr();
void scheduler_priority();
void cpu_utilization();
void print_gantt_chart();

int main() {

<<<<<<< HEAD
    printf("=== EduOS Simulator ===\n\n");

    // Create processes
=======
    printf("=== EDUOS SIMULATOR ===\n\n");

    // sample processes
>>>>>>> 92c1c7c (Add EDOUS project report and 16-slide presentation)
    create_process("Chrome", 1, 5);
    create_process("VSCode", 2, 3);
    create_process("Terminal", 0, 4);

    // threads
    create_thread(101, 1, "Chrome Renderer");
    create_thread(102, 1, "GPU Process");
    create_thread(201, 2, "VSCode Extension Host");

<<<<<<< HEAD
    // Display processes
    display_processes();

    // Display threads
    display_threads();
=======
    int choice;

    do {
        printf("\n===== EDUOS MENU =====\n");
        printf("1. FCFS Scheduler\n");
        printf("2. Round Robin\n");
        printf("3. Priority Scheduling\n");
        printf("4. CPU Utilization\n");
        printf("5. Gantt Chart\n");
        printf("6. Display Processes\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1: scheduler(); break;
            case 2: scheduler_rr(); break;
            case 3: scheduler_priority(); break;
            case 4: cpu_utilization(); break;
            case 5: print_gantt_chart(); break;
            case 6: display_processes(); break;
        }

    } while(choice != 0);
>>>>>>> 92c1c7c (Add EDOUS project report and 16-slide presentation)

    // FCFS Scheduling Demo
    Process p[3] = {
        {1, 5, 0, 0},
        {2, 3, 0, 0},
        {3, 8, 0, 0}
    };

    printf("\n=== FCFS Scheduling ===\n");

    fcfs(p, 3);

    return 0;
}