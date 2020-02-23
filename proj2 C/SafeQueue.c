#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "parameters.h"
#include "datatypes.h"
//#include "functions.h"

// SafeQueue Code

typedef struct SafeQueue {
  Task *buffer; // this is the array that holds the Task objects for the queue
  // this is the number of items the buffer can hold based on the number of slaves
  int length; 
  int nextIn; // next index where a task is added to the Queue
  int nextOut; // next index where a task is
  sem_t mutex; // this is the lock for the Queue
  sem_t onQueue; // number of items on the Queue
  sem_t tillFull; // number of items till the Queue is full
  
} SafeQueue;

//constructor for the SafeQueue
SafeQueue *init_SafeQueue(int len) {
  SafeQueue *queue = (SafeQueue *) malloc(sizeof(SafeQueue));
  queue->length = len; 
  queue->buffer = (Task *) malloc(len * sizeof(Task)); //amount of space needed for n tasks
  queue->nextIn = 0; //0 based index
  queue->nextOut = 0; //0 based index
  sem_init(&queue->mutex, 0, 1); // create the semaphore with a mutex value of 1
  sem_init(&queue->onQueue, 0, 0); // create a semaphore for the counter of tasks on the queue with a value of 0
  sem_init(&queue->tillFull, 0, (len-1)); //len-1 for max capicity because the insert happens at i+1
  return queue;
}

// returns true or false if the queue is empty
int  SafeQueue_empty(SafeQueue *queue) {
  return (queue->nextIn == queue->nextOut); //if the value for the index of where the next item will be placed equals the index value of the next index to be removed then return true
}

// increments the index for the position to be added to the queue with a circular buffer
int SafeQueue_indexPlus(SafeQueue *queue, int index) {
  return (index+1) % queue->length;
}

// adds a item to the next position in the queue 
void SafeQueue_push(SafeQueue *queue, Task item) {
  sem_wait(&queue->tillFull); // lock the counter for how many items can be added to the queue 
  sem_wait(&queue->mutex); // grab the lock for being in the critical section

  queue->buffer[queue->nextIn] = item; // at the index nextIn add the new task to the queue
  queue->nextIn = SafeQueue_indexPlus(queue, queue->nextIn); //increments the index for next call of push
  
  sem_post(&queue->mutex); // return the lock for being in the critical section
  sem_post(&queue->onQueue); // signal the semaphore for number of items on the queue
  
}

// removes the next item in the queue 
Task SafeQueue_poll(SafeQueue *queue) {
  sem_wait(&queue->onQueue); // lock the counter for how many items are on the queue 
  sem_wait(&queue->mutex); // grab the lock for being in the critical section

  Task item = queue->buffer[queue->nextOut]; // at the index nextOut grab the task from the queue
  queue->nextOut = SafeQueue_indexPlus(queue, queue->nextOut); //increments the index for next call of push
  
  sem_post(&queue->mutex); // return the lock for being in the critical section
  sem_post(&queue->tillFull); // signal the semaphore for number of items till the queue is full

  return item;
}

// for testing of SafeQueue
int main() {

  SafeQueue test = *init_SafeQueue(5);
  int qEmpty = SafeQueue_empty(&test);
  Task tTask;
  tTask.id = 1;
  tTask.length = 1;

  printf("The value of Queue Empty is: %d\n", qEmpty);

  SafeQueue_push(&test, tTask);
  Task currTask =  test.buffer[0];
  int idAtCurrLoc = currTask.id;
  int lenCurrtask = currTask.length;

  printf("the current task in the queue has a id: %d and length: %d\n", idAtCurrLoc, lenCurrtask);

  Task polledTask = SafeQueue_poll(&test);
  int idPolled = polledTask.id;
  int lengthPolled = polledTask.length;

  printf("the tasked polled has id: %d and length: %d\n", idPolled, lengthPolled);
  
  return 0;
}
