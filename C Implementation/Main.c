#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "includes/parameters.h"
#include "includes/datatypes.h"
#include "includes/functions.h"

// Main function
int main(int argc, char *argv[]) {
    // Configure parameters with program arguments (if provided)
    if (argc > 1) {
        num_slaves = strtol(argv[1], NULL, 10);
    } else {
        num_slaves = 5; // Default
    }

    if (argc > 2) {
        max_task_len = strtol(argv[2], NULL, 10);
    } else {
        max_task_len = 20; // Default
    }

    if (argc > 3) {
        max_master_idle = strtol(argv[3], NULL, 10);
    } else {
        max_master_idle = 10; // Default
    }

    // Print program settings
    printf("C Program: with settings:\n");
    printf("  Nslaves = %d\n", num_slaves);
    printf("  MaxTaskLength = %ds\n", max_task_len);
    printf("  MasterMaxIdle = %ds\n", max_master_idle);

    // Create SafeQueue
    SafeQueue queue = *init_SafeQueue(num_slaves);
  
    // Create and run master thread
    pthread_t master;
    pthread_create(&master, NULL, run_master, (void *) &queue);

    // Create and run slave threads
    pthread_t slaves[num_slaves];

    // Assign memory for the paramaters to call run_slave for each thread
    slaveArgs args[num_slaves]; 
    for (int thread = 0; thread < num_slaves; thread++) {
        slaveArgs argsTemp = { argsTemp.id = thread + 1, argsTemp.queue = &queue };
        args[thread] = argsTemp;
        pthread_create(&slaves[thread], NULL, run_slave, (void *) &args[thread]);
    }

    // Wait until master thread is done (do not exit main function)
    pthread_join(master, NULL);

    return EXIT_SUCCESS;
}

// Print thread message to console
void log(char *thread, char *message) {
    // Get current time [hh:mm:ss]
    time_t current_time;
    struct tm *timeinfo;
    time(&current_time);
    timeinfo = localtime(&current_time);
    char time_string[9];
    strftime(time_string, 9, "%H:%M:%S", timeinfo);

    // Print to console
    printf("[%s] %s > %s\n", time_string, thread, message);
}