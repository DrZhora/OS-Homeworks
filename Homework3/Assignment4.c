#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
   
    pid_t pid1, pid2;
    int status1, status2;
    
    pid1 = fork();
    
    if (pid1 < 0) {
        perror("First fork failed");
        exit(1);
    }
    else if (pid1 == 0) {
        printf("Child 1 (PID: %d) starting\n", getpid());
        printf("Child 1 (PID: %d) exiting with status 42\n", getpid());
        exit(42);
    }
    else {
        pid2 = fork();
        
        if (pid2 < 0) {
            perror("Second fork failed");
            exit(1);
        }
        else if (pid2 == 0) {
            printf("Child 2 (PID: %d) starting\n", getpid());
            printf("Child 2 (PID: %d) exiting with status 84\n", getpid());
            exit(84);
        }
        else {

            printf("Parent (PID: %d) waiting for children to finish\n", getpid());

            pid_t wpid1 = waitpid(pid1, &status1, 0);

            if (wpid1 == -1) {
                perror("Error waiting for child 1");
            }
            else {
                if (WIFEXITED(status1)) {
                    printf("Child 1 (PID: %d) exited normally with status: %d\n",
                           wpid1, WEXITSTATUS(status1));
                }
                else if (WIFSIGNALED(status1)) {
                    printf("Child 1 (PID: %d) terminated by signal: %d\n",
                           wpid1, WTERMSIG(status1));
                }
            }

            pid_t wpid2 = waitpid(pid2, &status2, 0);
            
            if (wpid2 == -1) {
                perror("Error waiting for child 2");
            }
            else {
                if (WIFEXITED(status2)) {
                    printf("Child 2 (PID: %d) exited normally with status: %d\n",
                           wpid2, WEXITSTATUS(status2));
                }
                else if (WIFSIGNALED(status2)) {
                    printf("Child 2 (PID: %d) terminated by signal: %d\n",
                           wpid2, WTERMSIG(status2));
                }
            }

            printf("Parent (PID: %d) finishing\n", getpid());
        }
    }
    
    return 0;
}
