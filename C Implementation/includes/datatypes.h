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