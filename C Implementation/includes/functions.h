// Print thread message to console
void log(char *thread, char *message);

// Run function for master thread
void *run_master(void *arg);

// Run function for slave threads
void *run_slave(void *id);

// Generate a task with a length between 1 and maxLength
Task generateTask(int maxLength);
