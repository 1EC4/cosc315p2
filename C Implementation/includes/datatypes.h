#include <semaphore.h>

// Declare struct for Master
typedef struct Master {
    int wait_time;
    int max_length;
    int max_idle;
    int max_slaves;
} Master;

// Declare struct for Task
typedef struct Task {
    int id;
    int length;
} Task;

// Declare struct for the SafeQueue
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

// Arguements for the run slave function
typedef struct slaveArgs {
  int id; // id for the slave
  SafeQueue* queue; // pointer to the queue
} slaveArgs;