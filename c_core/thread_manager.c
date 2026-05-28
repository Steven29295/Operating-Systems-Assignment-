#include <stdio.h>
#include <string.h>
#include "include/eduos.h"
<<<<<<< HEAD
#define MAX_THREADS 20

static TCB thread_table[MAX_THREADS];
static int thread_count = 0;
=======

/* ✅ DEFINE GLOBAL VARIABLES HERE */
TCB thread_table[MAX_THREADS];
int thread_count = 0;
>>>>>>> 92c1c7c (Add EDOUS project report and 16-slide presentation)

void create_thread(int tid, int parent_pid, const char *name) {

    if (thread_count >= MAX_THREADS) {
        printf("Thread table full!\n");
        return;
    }

    thread_table[thread_count].tid = tid;
    thread_table[thread_count].parent_pid = parent_pid;

    strncpy(thread_table[thread_count].name, name, 49);
    thread_table[thread_count].name[49] = '\0';

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