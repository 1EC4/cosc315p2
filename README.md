# COSC 315: Operating Systems - Project 2

### Table of Contents
- [Description](#description)
- [Core Features](#core-features)
- [Design Choices](#design-choices)
- [Sample Output](#sample-output)
- [Contributors](#contributors)

## Description

_Explain the design of your program and how syncronization works._

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
  
## Build instructions

Clone the project to a local repository:
`git clone https://github.com/1EC4/cosc315p2.git`

**Java Implementation:**



**C Implementation:**
Change to C Implementation directory

`cd cosc315p2/C Implementation`

Build the program

`make Program`

Run the program

`./Program`

## Sample Output
Check out [this example file](sample_output.txt) for sample output.

## Contributors
**Anthony Boyko**
  - 
  - 
  - 
  - 
  - 

**Nick Rieske**
  - 
  - 
  - 
  - 
  - 

**Jonathan Gresl**
  - 
  - 
  - 
  - 
  - 

## Programming Experience

_Add a brief discussion describing your experience implementing this problem in Java and C_

_Comment on the amount of effort and ease of coding the problem in different languages_

_Add assessment(s) to ZIp file before submitting (Does everyone submit separately?)_

[Back to The Top](#cosc-315-operating-systems---project-2)
