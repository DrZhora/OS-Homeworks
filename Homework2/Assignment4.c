#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    
    pid_t pid = fork();
    
    if (pid == 0) {
        execl("/bin/grep","grep", "main", "test.txt", NULL);
        perror("Execl failed");
        return 1;
    }

    wait(NULL); 
    printf("Parent process completed\n");


   
    return 0;
}