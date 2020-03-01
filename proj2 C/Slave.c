#include <stdio.h>
#include <stdlib.h>
#include "includes/parameters.h"
#include "includes/datatypes.h"
#include "includes/functions.h"

// Run function for slave threads
void *run_slave(slaveArgs *args) {
    int thread_id = args->id;
    char thread[3];
    while(TRUE) {
        
        sprintf(&thread, "S%d", thread_id);
        char message[] = "Idle";
	log(thread, message);

	
	Task request = SafeQueue_poll(args->queue);

	
        // Print thread message to console
        sprintf(&message, "Task %d with length %d received", request.id, request.length);
        log(thread, message);

        // Busy slave threads are set to sleep for the duration of the request length
        //int length = (rand() % MAX_TASK_LEN) + 1;
        sleep(request.length);


	//print finished tasked  to console
	sprintf(&message, "Task %d finished", request.id);
        log(thread, message);
	
    }

    return NULL;
}
