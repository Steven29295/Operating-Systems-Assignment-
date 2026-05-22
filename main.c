#include <stdio.h>
#include "include/eduos.h"

int main() {

    create_process(1, "Chrome");
    create_process(2, "VSCode");
    create_process(3, "Spotify");

    run_process(2);
    terminate_process(3);

    display_processes();

    return 0;
}