// Print thread message to console
void log(char *thread, char *message);

// Run function for master thread
void *run_master(void *queue);

// Run function for slave threads
void *run_slave(slaveArgs *args);

// Generate a task with a length between 1 and maxLength
Task generateTask(int maxLength);

// Constructor for the SafeQueue
SafeQueue *init_SafeQueue(int len);

// Returns true or false if the queue is empty
int  SafeQueue_empty(SafeQueue *queue);

// Increments the index for the position to be added to the queue with a circular buffer
int SafeQueue_indexPlus(SafeQueue *queue, int index);

// Adds a item to the next position in the queue 
void SafeQueue_push(SafeQueue *queue, Task item);

// Removes the next item in the queue 
Task SafeQueue_poll(SafeQueue *queue);