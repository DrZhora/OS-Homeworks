#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10
#define FINAL_SIZE 5

int main() {
    int *ptr;

    ptr = (int *)malloc(INITIAL_SIZE * sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers (separated by spaces): ", INITIAL_SIZE);
    for (int i = 0; i < INITIAL_SIZE; i++) {
        scanf("%d", &ptr[i]);
    }

    ptr = (int *)realloc(ptr, FINAL_SIZE * sizeof(int));
    
    
    printf("Array after resizing: ");
    for (int i = 0; i < FINAL_SIZE; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);

    return 0;
}
