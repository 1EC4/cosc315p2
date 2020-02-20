#include <stdio.h>
#include <stdlib.h>
#include "parameters.h"
#include "datatypes.h"


//generates a task with a random length 
Task genRandTask(int maxLen){
  int len = ( rand() % maxLen ) + 1;
  if ( nextId >= 0 ) {
    nextId++;
  }
  //note these two error don't stop the problem but just flagged them so they can be fixed elsewhere if they occur
  else if (nextId < 0) {
    printf("Error negative task id");
  }
  else { // this is for if the value is null just set it to one because that means no tasks have been generated.
    //however still flag with a print that taskId needs to be initialized in the main file
    printf("Error taskId hasn't been initialized");
    nextId = 1; 
  }

  Task newTask = {.id = nextId, .length = len};
  return newTask;
  
}

  //this is just the test code for this file, uncomment if you want to test functionality
/*
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
  
*/
