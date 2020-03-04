# COSC 315: Operating Systems - Project 2

### Table of Contents
- [Description](#description)
- [Core Features](#core-features)
- [Design Choices](#design-choices)
- [Build Instructions](#build-instructions)
- [Sample Output](#sample-output)
- [Contributors](#contributors)
- [Programming Experience](#programming-experience)

## Description

The program creates multiple threads - one master thread and N slave threads - to produce and consume requests. The master thread periodically produces requests and puts them into a request queue. The slave threads remove the requests from the queue and processes them for a duration equal to the request’s length. With all threads sharing the same bounded buffer resource, they must take turns accessing the resource. To ensure the threads don't interfere with each other, the threads must also acquire and release locks before reading or writing to the shared resource.

The Java Implementation and the C Implementation programs are built similarly. The main difference between the two programs is how synchronization is achieved; the Java Implementation uses monitors while the C Implementation uses semaphores. In both cases, the synchronization methods are applied to the pop and pull functions of the request queue.

## Core Features
**Request scheduling using threads and synchronization:**
- [x] The master thread sleeps from a random short duration and produces a request
- [x] Each request is assigned a sequentially increasing ID and a random length between 1 and M seconds
- [x] The master thread inserts the request into the request queue and then returns to sleep
- [x] If the request queue is full, the master threads waits until the request can be inserted
- [x] Idle slave threads wait for and process requests from the request queue
- [x] Busy slave threads are set to sleep for the duration of the request length
- [x] Master and slave threads print feedback to the console

## Design Choices
  1. Dispatch requests using a bounded buffer producer-consumer framework
  2. Synchronization implemented in Java using monitors
      - Uses space-limited queue object
      - Uses `synchronized` java keyword to lock critical sections
      - Uses methods from the java object `ArrayBlockingQueue`
  3. Synchronization implemented in C using semaphores
      - Uses 1 binary semaphore for locking the critical section
      - Uses 1 non-binary semaphore for tracking how many items can be added to the queue
      - Uses 1 non-binary semaphore for tracking how many tasks are on the queue
    
We chose C because as a group we were more familar with C over C++. So even though C++ is object oriented like java and would have made converting the problem between languages easier, C was chosen because the time spent learning how to program in C++ looked like it would outweigh the extra challenge of doing the problem in C. Also 3 semaphores were used rather than just the mutex with integer counters because this gets rid of the requirement of "check empty" and "check full" functions along with simplfying how push and poll are used in the master and slave files.   
  
## Build instructions

  1. Clone the project to a local repository:   `git clone https://github.com/1EC4/cosc315p2.git`
  
**Java Implementation:**

  2. Navigate to the Java directory: `cd "cosc315p2/Java Implementation"`
  3. Build the program: `make`
  4. Run the program (arguments optional): `java Main [num_slaves] [max_task_len] [max_master_idle]`
        - Examples: `java Main` or `java Main 5` or `java Main 5 20` or `java Main 5 20 10`
  
**C Implementation:**

  2. Navigate to the C directory: `cd "cosc315p2/C Implementation"`
  3. Build the program: `gcc -w -o Program Main.c Master.c SafeQueue.c Slave.c Task.c -pthread` or `make`
  4. Run the program (arguments optional): `./Program [num_slaves] [max_task_len] [max_master_idle]`
        - Examples: `./Program` or `./Program 5` or `./Program 5 20` or `./Program 5 20 10`

## Sample Output
Check out [this example file](sample_output.txt) for sample output.

## Contributors
- **Anthony Boyko**
  - Organization - Setup weekly meetings and communicated the project requirements
  - Java Implementation - Tested and confirmed functionality aligns with assignment guidelines
  - C Implementation - Setup the program framework based on the Java implementation
  - C Implementation - Created header files for the parameters, datatypes, and functions
  - C Implementation - Built the SafeQueue using semaphores for concurrency
  - C Implementation - Implemented task generation and integrated with run-master function
  - C Implementation - Integrated SafeQueue push and poll functions with run_master and run_slave functions
  - README - Commented on the effort and ease of coding the problem in different languages
  - Group Assessment - Completed individual group assessment and uploaded to Canvas (without project files)
  
- **Nick Rieske**
  - Organization - Setup GitHub repository with inital code and shared with group members
  - Java Implementation - Setup the program framework based on the object oriented model
  - Java Implementation - Built the main function to create and run the master and slave threads
  - Java Implementation - Built the master class with default run function
  - Java Implementation - Built the slave class with default run function
  - Java Implementation - Built the SafeQueue using monitors for concurrency
  - Java Implementation - Integrated SafeQueue push and poll functions with the master and slave threads
  - Java Implementation - Built helper method for determining current time and printing output to console
  - C Implemention - tested and confirmed functionality aligns with assignment guidelines
  - Sample Output - Added sample out put from Java Implementation
  - Makefile - Built Makefile for the Java Implementation to the create executable file
  - README - Added build instructions for the Java Implementation and described command line arguments
  - README - Added a brief discussion describing your experience implementing this problem in Java and C
  - Group Assessment - Completed individual group assessment and uploaded to Canvas (without project files)

- **Jonathan Gresl**
  - Java Implementation - Tested and confirmed functionality aligns with assignment guidelines
  - C Implementation - Framed out the main function to create and run the master and slave threads
  - C Implementation - Framed out the run_master and run_slave functions to sleep and print output
  - C Implementation - Built helper method for determining current time and printing output to console
  - C Implementation - Added functionality to accept command line arguments to configure parameters
  - Sample Output - Added sample output from C Implementation
  - Makefile - Built Makefile for the C implementation to create the executable file
  - README - Added the description and how syncronization works
  - README - Framed out README template and and created linked sections for each assignment expectation
  - README - Added the core features and design choices for the program
  - README - Added build instructions for the C Implementation and described command line arguments
  - README - Updated the contributions section as work was completed
  - Group Assessment - Completed individual group assessment and uploaded to Canvas (with project files)

## Programming Experience

  Most of the exercise was relatively straight-forward to implement and test; however, one problem was how to implement
and test the locks/monitors. Testing those required running the program at different settings and ensuring that the log 
output was consistent with the expectations. Implementation in Java was easily achieved using the `synchronized` keyword
while in C, semaphores doesn't guarantee synchronization between multiple resources as a built in feature. This required learning how C's semaphore library can be combined with a user created data structure to achieve the same task.

[Back to The Top](#cosc-315-operating-systems---project-2)
