#include <stdio.h>
#include <stdlib.h>
#include "includes/parameters.h"
#include "includes/datatypes.h"
#include "includes/functions.h"

// Run function for slave threads
void *run_slave(void *id) {
    while(TRUE) {
        int thread_id = (int) id;
        char thread[3];
        sprintf(&thread, "S%d", thread_id);
        char message[] = "Idle";

        // Idle slave threads wait for and process requests from the request queue
        Task request = generateTask(MAX_TASK_LEN); // TODO: Remove generate when queue is ready to poll from
        int queueEmpty = TRUE;
        while(queueEmpty == TRUE) { // TODO: If queue is not empty, poll
            sleep(WAIT_TIME);
            queueEmpty = FALSE;
        }

        // Print thread message to console
        sprintf(&message, "Task %d with length %d received", request.id, request.length);
        log(thread, message);

        // Busy slave threads are set to sleep for the duration of the request length
        sleep(request.length);
    }

    return NULL;
}