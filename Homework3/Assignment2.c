#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    
    pid_t pid1, pid2;
    int status;

    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid1 == 0) {
        printf("Child 1 process. PID: %d\n", getpid());
        exit(10);  
    }
    else {
        pid_t cpid = wait(&status);
        if (WIFEXITED(status)) {
            printf("Parent: Child %d exited with status %d\n",
                   cpid, WEXITSTATUS(status));
        }

        printf("Parent process (PID: %d) continuing...\n", getpid());

        pid2 = fork();

        if (pid2 < 0) {
            perror("Fork failed");
            return 1;
        }
        else if (pid2 == 0) {
            printf("Child 2 process. PID: %d\n", getpid());
            exit(20);  
        }
        else {

            cpid = waitpid(pid2, &status, 0);
            if (WIFEXITED(status)) {
                printf("Parent: Child %d exited with status %d\n",
                       cpid, WEXITSTATUS(status));
            }

            printf("Parent process (PID: %d) done.\n", getpid());
        }
    }
    return 0;
}
