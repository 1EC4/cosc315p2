#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "includes/parameters.h"
#include "includes/datatypes.h"
#include "includes/functions.h"

// Main function
int main() {
    // Create and run master thread
    pthread_t master;
    pthread_create(&master, NULL, run_master, NULL);

    // Create and run slave threads
    pthread_t slaves[NUM_SLAVES];
    for (int thread = 0; thread < NUM_SLAVES; thread++) {
        pthread_create(&slaves[thread], NULL, run_slave, (void *) thread+1);
    }

    // Wait until threads are done (do not exit main function)
    pthread_join(master, NULL);
    // for (int thread = 0; thread < NUM_SLAVES; thread++) {
    //    pthread_join(slaves[thread], NULL);
    // }

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