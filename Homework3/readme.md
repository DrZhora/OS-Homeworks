# Operating Systems - Process Management Assignments

This directory contains five assignments demonstrating various aspects of process management in Linux using C programming.

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

**Key Observations:**
- First child exits with status 10
- Second child exits with status 20
- Parent process waits for each child specifically using `waitpid()`

## Assignment 3: Understanding atexit()
Located in `Assignment3.c`

This program demonstrates process cleanup using the `atexit()` function:
- Registers multiple cleanup functions
- Shows LIFO (Last In First Out) order of cleanup function execution
- Demonstrates different program termination methods:
  1. Normal return from main
  2. Using `exit()`
  3. Using `_exit()`

**Key Behaviors:**
- Cleanup functions are called automatically on normal program termination
- `_exit()` bypasses cleanup functions
- Functions registered with `atexit()` are called in reverse order of registration

## Assignment 4: Fork and Exit Status
Located in `Assignment4.c`

This assignment focuses on handling multiple child processes and their exit statuses:
- Creates two child processes
- Each child returns a different exit code
- Parent process uses `waitpid()` to wait for specific children
- Demonstrates how to check whether processes exited normally or due to signals

**Process Behavior:**
1. Parent creates two child processes
2. Child 1 exits with status 42
3. Child 2 exits with status 84
4. Parent waits for each child specifically and reports their exit status
5. Program demonstrates proper error handling for fork and wait operations

## Assignment 5: Handling Zombie Processes
Located in `Assignment5.c`

This program demonstrates zombie process creation and prevention:

### Part 1: Creating a Zombie Process
- Creates a child process that exits immediately
- Parent sleeps without calling `wait()`
- Child becomes a zombie process
- Can be observed using:
  ```bash
  ps -l | grep Z
  # or
  ps aux | grep defunct
  ```

### Part 2: Preventing Zombie Processes
- Creates a child process
- Parent properly waits for child termination
- No zombie process is created
- Demonstrates proper process cleanup

**Understanding Zombie Processes:**
- A zombie process is a process that has completed execution but still has an entry in the process table
- This happens when a parent doesn't collect child's exit status using `wait()` or `waitpid()`
- Zombie processes consume system resources and should be avoided
- Proper use of `wait()` or `waitpid()` prevents zombie processes

### How to Run the Programs

1. Compile any program:
   ```bash
   gcc AssignmentN.c -o AssignmentN
   ```

2. Run the compiled program:
   ```bash
   ./AssignmentN
   ```

### Common Patterns Across Assignments

1. **Process Creation:**
   - All assignments use `fork()` to create child processes
   - Fork returns:
     - Negative value: error
     - Zero: in child process
     - Positive value: in parent process (child's PID)

2. **Process Synchronization:**
   - `wait()`: Waits for any child to terminate
   - `waitpid()`: Can wait for specific child process
   - Both return exit status information

3. **Error Handling:**
   - All programs check for fork failures
   - Wait operations are verified
   - Exit status is properly checked using macros like `WIFEXITED()` and `WIFSIGNALED()`

4. **Process Termination:**
   - Normal return from main
   - `exit()`: Clean termination with cleanup
   - `_exit()`: Immediate termination without cleanup

### Best Practices Demonstrated

1. Always check return values of system calls
2. Properly handle error conditions
3. Clean up resources in parent processes
4. Avoid zombie processes through proper waiting
5. Use appropriate exit status codes
6. Include clear process identification in output

These assignments provide practical experience with fundamental operating system concepts related to process management and synchronization.


## Github Repo link
https://github.com/DrZhora/OS-Homeworks 
