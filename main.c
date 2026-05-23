#include <stdio.h>
#include "include/eduos.h"

int main() {

    create_process(1, "Chrome");
    create_process(2, "VSCode");

    create_thread(101, 1, "Chrome Renderer");
    create_thread(102, 1, "Chrome GPU");
    create_thread(201, 2, "VSCode Extension Host");

    scheduler();

    display_processes();

    display_threads();

    return 0;
}