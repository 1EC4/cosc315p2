#include <stdio.h>
#include <stdlib.h>
#include "includes/parameters.h"
#include "includes/datatypes.h"
#include "includes/functions.h"

// Run function for master thread
void *run_master(void *arg) {
    while(TRUE) {
        // Sleep for a random duration between 1 and MAX_MASTER_IDLE (seconds)
        int master_sleep = (rand() % MAX_MASTER_IDLE) + 1;

        // Print thread message to console
        char thread[] = "MT";
        char message[30];
        sprintf(&message, "Going to sleep for %d seconds", master_sleep);
        log(thread, message);
        
        // Activate sleep for N seconds
        sleep(master_sleep);

        // The master thread produces a new request
        Task request = generateTask(MAX_TASK_LEN);
        
        // Print thread message to console
        sprintf(&message, "Task %d with length %d generated", request.id, request.length);
        log(thread, message);

        // TODO: The master thread inserts the request into the request queue and then returns to sleep

        // TODO: If the request queue is full, the master threads waits until the request can be inserted

    }
    return NULL;
}