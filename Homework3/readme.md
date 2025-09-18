
## Assignment 1: Understanding wait() and waitpid()
Located in `Assignment1.c`

This assignment demonstrates basic process creation and synchronization using `fork()` and `wait()`. The program:
1. Creates a child process using `fork()`
2. Makes the parent process wait for the child to complete
3. Shows process IDs and basic parent-child relationships

## Assignment 2: Using wait() and waitpid()
Located in `Assignment2.c`

This program demonstrates more advanced process synchronization:
- Creates two child processes sequentially
- Uses both `wait()` and `waitpid()` for process synchronization
- Shows how to check and handle process exit status
- Demonstrates the difference between waiting for any child vs a specific child

## Assignment 3: Understanding atexit()
Located in `Assignment3.c`

This program demonstrates process cleanup using the `atexit()` function:
- Registers multiple cleanup functions
- Shows LIFO (Last In First Out) order of cleanup function execution
- Demonstrates different program termination methods:
  1. Normal return from main
  2. Using `exit()`
  3. Using `_exit()`


## Assignment 4: Fork and Exit Status
Located in `Assignment4.c`

This assignment focuses on handling multiple child processes and their exit statuses:
- Creates two child processes
- Each child returns a different exit code
- Parent process uses `waitpid()` to wait for specific children
- Demonstrates how to check whether processes exited normally or due to signals


## Assignment 5: Handling Zombie Processes
Located in `Assignment5.c`

This program demonstrates zombie process creation and prevention:

### Part 1: Creating a Zombie Process
- Creates a child process that exits immediately
- Parent sleeps without calling `wait()`
- Child becomes a zombie process
- Can be observed using:
  ```bash
  ps aux | grep defunct
  ```

### Part 2: Preventing Zombie Processes
- Creates a child process
- Parent properly waits for child termination
- No zombie process is created
- Demonstrates proper process cleanup



## Github Repo link
https://github.com/DrZhora/OS-Homeworks 
