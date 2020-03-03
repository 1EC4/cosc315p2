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

**_TODO: Explain the design of your program and how syncronization works._**

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
  3. Synchronization implemented in C using semaphores
  
  **_TODO: README - Explain and motivate the design choices_**
  
## Build instructions

  1. Clone the project to a local repository:   `git clone https://github.com/1EC4/cosc315p2.git`
  
**Java Implementation:**

  2. Navigate to the Java directory: `cd "cosc315p2/Java Implementation"`
  3. Build the program: `make`
  4. Run the program: `java Main`
  
   **_TODO: README - Describe any command line arguments to specify parameters for the Java Implementation_**
  
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
  - Java Implementation - tested and confirmed functionality aligns with assignment guidelines
  - C Implementation - Setup the program framework based on the Java implementation
  - C Implementation - Created header files for the parameters, datatypes, and functions
  - C Implementation - Built the SafeQueue using semaphores for concurrency
  - C Implementation - Implemented task generation and integrated with run-master function
  - C Implementation - Integrated SafeQueue push and poll functions with run_master and run_slave functions
  - **_README - Commented on the effort and ease of coding the problem in different languages_**
  - **_Group Assessment - Completed individual group assessment and uploaded to Canvas (without project files)_**
  
- **Nick Rieske**
  - Organization - Setup GitHub repository with inital code and shared with group members
  - Java Implementation - Setup the program framework based on the object oriented model
  - Java Implementation - Built the main function to create and run the master and slave threads
  - Java Implementation - Built the master class with default run function
  - Java Implementation - Built the slave class with default run function
  - Java Implementation - Built the SafeQueue using monitors for concurrency
  - Java Implementation - Integrated SafeQueue push and poll functions with the master and slave threads
  - Java Implementation - Built helper method for determining current time and printing output to console
  - **_C Implemention - tested and confirmed functionality aligns with assignment guidelines_**
  - Sample Output - Added sample out put from Java Implementation
  - Makefile - Built Makefile for the Java Implementation to the create executable file
  - README - Added build instructions for the Java Implentation **_and described command line arguments_**
  - **_README - Added a brief discussion describing your experience implementing this problem in Java and C_**
  - **_Group Assessment - Completed individual group assessment and uploaded to Canvas (without project files)_**

- **Jonathan Gresl**
  - Java Implementation - tested and confirmed functionality aligns with assignment guidelines
  - C Implementation - Framed out the main function to create and run the master and slave threads
  - C Implementation - Framed out the run_master and run_slave functions to sleep and print output
  - C Implementation - Built helper method for determining current time and printing output to console
  - C Implementation - Added functionality to accept command line arguments to configure parameters
  - Sample Output - Added sample output from C Implementation
  - Makefile - Built Makefile for the C implementation to create the executable file
  - README - Framed out README template and and created linked sections for each assignment expectation
  - README - Added the core features and design choices for the program
  - README - Added build instructions for the C Implentation and described command line arguments
  - README - Updated the contributions section as work was completed
  - **_README - Added the design description and how syncronization works_**
  - **_README - Added explanation and motivation for the design choices_**
  - **_Group Assessment - Completed individual group assessment and uploaded to Canvas (with project files)_**

## Programming Experience

**_TODO: Add a brief discussion describing your experience implementing this problem in Java and C_**

**_TODO: Comment on the amount of effort and ease of coding the problem in different languages_**

[Back to The Top](#cosc-315-operating-systems---project-2)
