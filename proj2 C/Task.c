#include <stdio.h>
#include <stdlib.h>
#include "parameters.h"

typedef struct Task {
  
  int id; // id number of the task
  int length; // length of task in seconds

} Task;

//generates a task with a random length 
Task genRandTask(int maxLen){
  int len = ( rand() % maxLen ) + 1;
  //if ( nextId != null && nextId >= 0 ) {
  if ( nextId >= 0 ) {
    nextId++;
  }
  else {
    printf("Error taskId has been initialized");
    nextId = 1; 
  }

  Task newTask = {.id = nextId, .length = len};
  return newTask;
  
}

int main() {
  nextId = 0;

  for (int i = 0; i < 10; i++) {
      Task test  = genRandTask(10);
      int tId = test.id;
      int tLen = test.length;
      printf("ID: %d, Len: %d \n", tId, tLen); 

  }
  return 0;
}
