#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 * This program demonstrates zombie processes and their prevention.
 * 
 * A zombie process is a process that has completed execution but still has an entry 
 * in the process table. This happens when a child process terminates but the parent
 * hasn't read its exit status using wait() or waitpid().
 *
 * To observe the zombie process:
 * 1. Run this program
 * 2. In another terminal, run: ps -l | grep Z
 *    This will show processes in zombie state (Z)
 * 3. You can also use: ps aux | grep defunct
 *    This shows "defunct" processes (zombies)
 */

void create_zombie() {
    
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {

        printf("Child process (PID: %d) starting\n", getpid());
        printf("Child process will exit immediately\n");
        exit(0);
    }
    else {

        printf("Parent process (PID: %d) created child (PID: %d)\n", getpid(), pid);
        printf("Parent sleeping for 30 seconds - observe zombie state\n");
        printf("Run in another terminal:\n");
        printf("ps aux | grep defunct\n");    
        sleep(30);  
        printf("\nParent process exiting without waiting for child\n");
    }
}

void prevent_zombie() {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {

        printf("\nChild process (PID: %d) starting\n", getpid());
        printf("Child process will exit immediately\n");
        exit(0);
    }
    else {

        printf("\nParent process (PID: %d) created child (PID: %d)\n", getpid(), pid);
        printf("Parent will wait for child to prevent zombie\n");
        
        int status;
        pid_t child_pid = wait(&status);
        
        if (child_pid > 0) {
            if (WIFEXITED(status)) {
                printf("Child (PID: %d) exited normally with status: %d\n",
                       child_pid, WEXITSTATUS(status));
            }
            else if (WIFSIGNALED(status)) {
                printf("Child (PID: %d) terminated by signal: %d\n",
                       child_pid, WTERMSIG(status));
            }
        }
        
        printf("Parent process exiting after waiting for child\n");
    }
}

int main() {
    printf("Part 1: Demonstrating Zombie Process\n");
    printf("====================================\n");
    create_zombie();
    
    printf("\nPart 2: Preventing Zombie Process\n");
    printf("=================================\n");
    prevent_zombie();
    
    return 0;
}
