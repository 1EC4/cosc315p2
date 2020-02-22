#include <stdio.h>
#include <stdlib.h>
#include "includes/parameters.h"
#include "includes/datatypes.h"
#include "includes/functions.h"

// Run function for master thread
void *run_master(void *arg) {
    int master_sleep = (rand() % MAX_TASK_LEN) + 1;
    char thread[] = "MT";
    char message[30];
    sprintf(&message, "Going to sleep for %d seconds", master_sleep);

    log(thread, message);
    return NULL;
}