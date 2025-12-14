# Client-Server Programs

[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)](https://www.cprogramming.com/)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

A collection of three C programming tasks implementing different Client-Server communication patterns using socket programming.

## 📋 Table of Contents

- [Overview](#overview)
- [Tasks](#tasks)
  - [Task 1: String Transformation Server](#task-1-string-transformation-server)
  - [Task 2: File Transfer System](#task-2-file-transfer-system)
  - [Task 3: Armstrong Number Checker](#task-3-armstrong-number-checker)
- [Requirements](#requirements)
- [Compilation](#compilation)
- [Usage](#usage)
- [Project Structure](#project-structure)

## Overview

This repository contains three server implementations demonstrating different network programming concepts:
- **String processing** and transformation
- **File I/O** and transfer over network
- **Mathematical computation** with continuous client communication

## Tasks

### Task 1: String Transformation Server

**Objective:** Implement a Client-Server program where the client sends a string to the server, the server receives it, transforms it (converts to uppercase), and sends it back to the client as a response.

**Features:**
- Server listens on port `8080`
- Converts received string to uppercase before sending back
- Single request-response cycle
- Handles socket creation and connection errors

**File:** `task1.c`

### Task 2: File Transfer System

**Objective:** Implement a file transfer system where the client sends a request with a filename, and the server sends back the file's content if it exists.

**Features:**
- Server listens on port `8080`
- Reads file line by line and sends content to client
- Handles file not found errors gracefully
- Sends error message if file doesn't exist

**File:** `task2.c`

### Task 3: Armstrong Number Checker

**Objective:** Implement a Client-Server program where the client sends numbers entered by the user in an infinite loop. The server checks if the given number is an Armstrong number or not. If it matches the requirements, the server sends "Yes" as a response to the client, otherwise "No".

**Features:**
- Server listens on port `8080`
- Continuously receives numbers from client in a loop
- Checks if number is an Armstrong number
- Armstrong number: a number that equals the sum of its digits each raised to the power of the number of digits
- Example: `153 = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153`

**File:** `task3.c`

## Requirements

- GCC compiler
- Unix-like operating system (Linux, macOS)
- Math library (for Task 3)

## Compilation

Compile each task using the following commands:

```bash
# Task 1: String Transformation Server
gcc task1.c -o task1

# Task 2: File Transfer System
gcc task2.c -o task2

# Task 3: Armstrong Number Checker (requires math library)
gcc task3.c -o task3 -lm
```

## Usage

1. **Compile the desired task** (see [Compilation](#compilation))

2. **Run the server:**
   ```bash
   ./task1  # or ./task2 or ./task3
   ```

3. **Connect a client** using a network client program or implement a client to test the server functionality.

## Project Structure

```
Client_Server_in_C/
├── README.md          # Project documentation
├── task1.c            # String transformation server
├── task2.c            # File transfer system
└── task3.c            # Armstrong number checker
```

## Notes

- All tasks use port `8080` by default
- Make sure only one server is running at a time to avoid port conflicts
- Task 3 requires linking the math library (`-lm` flag) due to the `pow()` function
- These are server implementations only - you'll need to implement or use a client program to test them

## License

This project is open source and available for educational purposes.
