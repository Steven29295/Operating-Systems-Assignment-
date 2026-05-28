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

    // ✅ REQUIRED FOR FIXED SCHEDULING
    int remaining_time;
    int arrival_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;

    int owner_id;
} PCB;

// Thread Control Block (TCB)
typedef struct {
    int tid;
    int parent_pid;
    char name[50];
} TCB;

// ===== GANTT GLOBALS =====
extern int gantt_log[1000];
extern int gantt_index;

// ===== HELPER =====
void add_gantt(int pid);
void show_gantt_chart();

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
// ================= SCHEDULERS =================

void scheduler();                  // FCFS
void scheduler_rr();              // Round Robin
void scheduler_priority();        // Priority Scheduling

void cpu_utilization();           // CPU stats
void print_gantt_chart();         // Gantt chart
#endif