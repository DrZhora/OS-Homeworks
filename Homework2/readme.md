# Process Management and System Calls Analysis Report

## Overview
This report analyzes four programs that demonstrate various aspects of process management in Unix-like systems, focusing on the `fork()` and `execl()` system calls.

## Assignment 1: Simple Fork and Exec
### Program Flow
1. Main process starts
2. `fork()` system call creates a child process
3. Child process executes `ls` command using `execl()`
4. Parent process waits for child completion
5. Parent process prints completion message

### System Calls Analysis
- `fork()`:
  - Return value in parent: Child's PID (positive number)
  - Return value in child: 0
  - Return value on failure: -1
- `execl("/bin/ls", "ls", NULL)`:
  - Only returns if an error occurs
  - Completely replaces the child process image
- `wait(NULL)`:
  - Suspends parent process until child terminates
  - Returns child's PID on success
  - Returns -1 on error

### Process Hierarchy
```
Parent Process
    │
    └── Child Process (replaced by 'ls' command)
    |
```

## Assignment 2: Multiple Child Processes
### Program Flow
1. Main process starts
2. First `fork()` creates child for `ls` command
3. Parent waits for child to complete
4. Parent process creates second child for `date` command
5. Parent waits for child to complete
6. Parent prints completion message

### System Calls Analysis
- Two `fork()` calls:
  - Each creates a new process
  - Each child gets a unique PID
- Two `execl()` calls:
  - First child: `execl("/bin/ls", "ls", NULL)`
  - Second child: `execl("/bin/date", "date", NULL)`
- Two `wait(NULL)` calls:
  - Parent waits for both children to complete
  - Order of completion may vary

### Process Hierarchy
```
Parent Process
    │
    ├── Child Process 1 (ls command)
    │
    └── Child Process 2 (date command)
    |
```

## Assignment 3: Fork and Exec with Arguments
### Program Flow
1. Main process starts
2. `fork()` creates child process
3. Child executes `echo` with argument
4. Parent waits for completion
5. Parent prints message

### System Calls Analysis
- `fork()`: Same as previous assignments
- `execl("/bin/echo", "echo", "Hello from the child process", NULL)`:
  - First argument: path to executable
  - Second argument: program name 
  - Third argument: message to echo
  - Last argument: NULL terminator
- `wait(NULL)`: Ensures sequential output

### Process Hierarchy
```
Parent Process
    │
    └── Child Process (echo command with argument)
    |
```

## Assignment 4: Command with Multiple Arguments
### Program Flow
1. Main process starts
2. `fork()` creates child process
3. Child executes `grep` with pattern and file arguments
4. Parent waits for completion
5. Parent prints message

### System Calls Analysis
- `fork()`: Same as previous assignments
- `execl("/usr/bin/grep", "grep", "main", "test.txt", NULL)`:
  - More complex argument passing
  - Multiple arguments for the executed program
  - File I/O handled by grep process
- `wait(NULL)`: Ensures proper synchronization

### Process Hierarchy
```
Parent Process
    │
    └── Child Process (grep command with arguments)
    |
```


## Github Repo link
https://github.com/DrZhora/OS-Homeworks 