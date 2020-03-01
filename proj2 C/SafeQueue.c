#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "includes/datatypes.h"
#include "includes/parameters.h"

// SafeQueue Code

// constructor for the SafeQueue
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