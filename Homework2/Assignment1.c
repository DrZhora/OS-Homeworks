#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
   
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        execl("/bin/ls", "ls", NULL);
        perror("Execl failed");
        return 1;
    } else {
        wait(NULL);  // Wait for child to complete
        printf("Parent process done\n");
    }

    return 0;
}
