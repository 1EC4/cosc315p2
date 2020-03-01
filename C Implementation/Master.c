#include <stdio.h>
#include <stdlib.h>
#include "includes/parameters.h"
#include "includes/datatypes.h"
#include "includes/functions.h"

// Run function for master thread
void *run_master(void *queue) {
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
	
        // Add the task to the queue and if the queue is full SafeQueue_push will be asleep
        SafeQueue_push(queue, request);

        // Next iteration of the loop will put the master back to sleep
    }
    return NULL;
}