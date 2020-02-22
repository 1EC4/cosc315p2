#include <stdio.h>
#include <stdlib.h>
#include "includes/parameters.h"
#include "includes/datatypes.h"
#include "includes/functions.h"

// Run function for slave threads
void *run_slave(void *id) {
    int thread_id = (int) id;
    char thread[3];
    sprintf(&thread, "S%d", thread_id);
    char message[] = "Idle";
    
    log(thread, message);
    return NULL;
}