#include <stdio.h>
#include <string.h>
#include "include/eduos.h"
#define MAX_THREADS 20
static TCB thread_table[MAX_THREADS];
typedef struct {
    int tid;
    int parent_pid;
    char name[50];
} TCB;

TCB thread_table[10];
int thread_count = 0;

void create_thread(int tid, int parent_pid, char *name) {
    thread_table[thread_count].tid = tid;
    thread_table[thread_count].parent_pid = parent_pid;
    strcpy(thread_table[thread_count].name, name);
    thread_count++;

    printf("Thread %s (TID=%d) created under PID=%d\n",
           name, tid, parent_pid);
}

void display_threads() {
    printf("\n--- Thread Table ---\n");
    for (int i = 0; i < thread_count; i++) {
        printf("TID: %d | Parent PID: %d | Name: %s\n",
               thread_table[i].tid,
               thread_table[i].parent_pid,
               thread_table[i].name);
    }
}