#include <stdio.h>
#include <stdlib.h>
#include "includes/parameters.h"
#include "includes/datatypes.h"
#include "includes/functions.h"

// Delcare global variables for Task
next_id = 1;

// Generate a task with a length between 1 and maxLength
Task generateTask(int maxLength) {
    int length = (rand() % maxLength) + 1;
    Task newTask = {.id = next_id++, .length = length};
    return newTask;
}