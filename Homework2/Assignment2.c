#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    
    pid_t pid1, pid2;

    // Creating first child process
    pid1 = fork();

    if (pid1 == 0) {
        // Inside first child process 
        execl("/bin/ls", "ls", NULL);
        perror("Execl (ls) failed");
        return 1;
    } else {
        // Inside parent process,
        wait(NULL);   // Wait for first child to complete
        
        // Creating second child
        pid2 = fork();

        if (pid2 == 0) {
            // Inside second child process 
            execl("/bin/date", "date", NULL);
            perror("Execl (date) failed");
            return 1;
        } else {
            // Inside parent process,
            wait(NULL);  // Wait for second child to complete
            printf("Parent process done\n");
        }
    }

    return 0;
}
