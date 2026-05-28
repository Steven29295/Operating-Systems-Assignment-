

# EDOUS - Educational Operating System Simulation

## Project Information

| Field           | Details                                         |
| --------------- | ----------------------------------------------- |
| Course          | OS 2026                                         |
| Module Code     | 351 CS 2104                                     |
| Project Title   | EDOUS (Educational Operating System Simulation) |
| Student Name    | Steven Mpophiwa                                 |
| Student ID      | 25311351033                                     |
| Submission Date | April 30, 2026                                  |

---

# Project Overview

EDOUS is an educational operating system simulation project developed using C and Python. The project demonstrates fundamental operating system concepts including process management, CPU scheduling, multithreading, synchronization, and inter-process communication (IPC).

The system was created as part of the Operating Systems course to help students understand how operating systems manage processes, allocate CPU resources, and coordinate concurrent tasks.

The project combines low-level C programming with Python visualization tools to simulate realistic operating system behavior in an educational environment.

---

# Objectives

The main objectives of the project are:

* To simulate operating system process scheduling
* To implement process creation and management
* To demonstrate CPU scheduling algorithms
* To implement thread synchronization
* To simulate inter-process communication (IPC)
* To visualize process execution timelines
* To strengthen understanding of operating system concepts

---

# Features

## Process Management

* Process creation
* Process termination
* Process state transitions
* Process Control Block (PCB) simulation

## CPU Scheduling Algorithms

* First Come First Serve (FCFS)
* Round Robin Scheduling
* Priority Scheduling

## Thread Management

* Multithreading support
* Thread synchronization
* Race condition handling

## Inter-Process Communication (IPC)

* Shared memory communication
* Message passing simulation

## Visualization

* Scheduling timeline simulation
* Gantt chart generation
* CPU allocation tracking

---

# Technologies Used

## Programming Languages

* C
* Python

## Development Tools

* GCC Compiler
* Git & GitHub
* MSYS2 / MinGW
* Visual Studio Code
* PyCharm

## Python Libraries

* Matplotlib
* Pandas

---

# Prerequisites

Before running the EDOUS project, ensure the following software and tools are installed on your system.

---

## Required Software

### 1. GCC Compiler

Required for compiling the C source files.

### 2. Python 3.x

Required for running the scheduler simulation and visualization tools.

### 3. Git

Required for version control and GitHub integration.

### 4. MSYS2 or MinGW (Windows Users)

Provides GCC and Unix-like terminal support on Windows.

---

# Required Libraries

## C Libraries

* pthread library

## Python Packages

Install the required Python libraries using:

```bash id="4k8c1x"
pip install matplotlib pandas
```

---

# Environment Setup

## Windows Setup

Install:

* Python 3
* GCC Compiler
* Git
* MSYS2 or MinGW

Verify installation:

```bash id="0x8l2p"
gcc --version
python --version
git --version
```

---

## Linux Setup

Install required packages:

```bash id="7t3n1k"
sudo apt update
sudo apt install gcc python3 python3-pip git
```

Install Python libraries:

```bash id="x4z7a2"
pip install matplotlib pandas
```

---

# Hardware Requirements

* Minimum 4GB RAM
* 500MB Free Storage
* 64-bit Operating System

---

# Project Structure

```text id="h2m9vx"
Operating-Systems-Assignment/
│
├── c_core/
│   ├── main.c
│   ├── process_manager.c
│   ├── scheduler.c
│   ├── thread_manager.c
│   ├── ipc_module.c
│   ├── scheduler.h
│   └── eduos.exe
│
├── python_scheduler/
│   ├── scheduler_sim.py
│   ├── timeline.py
│   ├── gantt.py
│   ├── sample_process.csv
│   └── requirements.txt
│
├── screenshots/
├── docs/
└── README.md
```

---

# Compilation Instructions

Compile the project using GCC:

```bash id="s1d6r4"
gcc main.c process_manager.c thread_manager.c scheduler.c ipc_module.c -o eduos
```

Run the executable:

```bash id="c7v5f2"
./eduos
```

---

# Python Scheduler Simulation

Run the scheduler visualization:

```bash id="v8k3n5"
python scheduler_sim.py
```

Run the timeline visualization:

```bash id="l3p9q7"
python timeline.py
```

---

# Scheduling Algorithms

## First Come First Serve (FCFS)

Processes are executed in the order they arrive. This method is simple but may result in longer waiting times for short processes.

---

## Round Robin Scheduling

Each process receives a fixed time quantum. If execution is not completed within the allocated time, the process returns to the queue.

---

## Priority Scheduling

Processes with higher priority are executed first. This improves responsiveness for critical tasks.

---

# Process States

Processes transition through the following states:

* Ready
* Running
* Waiting
* Terminated

These states are managed by the process manager and scheduler modules.

---

# Thread Synchronization

The thread manager demonstrates concurrent execution and synchronization techniques used to avoid:

* Race conditions
* Deadlocks
* Data inconsistency

---

# Inter-Process Communication (IPC)

The IPC module allows communication between processes using:

* Shared memory
* Message passing

This demonstrates coordination between independent execution units.

---

# Testing

The project was tested under multiple scenarios including:

* Equal priority processes
* High CPU load
* Mixed scheduling workloads
* Concurrent thread execution

Testing confirmed proper scheduling and synchronization behavior.

---

# Challenges Faced

Some major challenges encountered during development include:

* Debugging segmentation faults
* Managing process queues
* Handling synchronization issues
* Integrating Python visualization with C modules

These challenges were solved through debugging and modular design improvements.

---

# Learning Outcomes

This project improved understanding of:

* Operating system architecture
* CPU scheduling
* Process lifecycle management
* Multithreading
* Synchronization
* IPC mechanisms
* System-level programming in C

---

# Future Improvements

Possible future enhancements include:

* Memory management simulation
* Deadlock detection algorithms
* Real-time scheduling
* GUI-based visualization
* Advanced IPC mechanisms

---

# GitHub Repository

Repository Link:

https://github.com/Steven29295/Operating-Systems-Assignment-

---

# Conclusion

The EDOUS project successfully demonstrates the practical implementation of operating system concepts using both C and Python. The project provides an educational platform for understanding scheduling algorithms, process management, multithreading, and inter-process communication in a simplified operating system environment.

