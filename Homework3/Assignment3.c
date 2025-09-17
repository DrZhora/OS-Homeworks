#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  


void cleanup1() {
    printf("Cleanup 1...\n");
}

void cleanup2() {
    printf("Cleanup 2...\n");
}

int main() {


    printf("Doing work\n");
    atexit(cleanup1);
    atexit(cleanup2);
    exit(0);
    // atexit() handlers are called in reverse order of registration from bottom to top

    
    return 0;

}
