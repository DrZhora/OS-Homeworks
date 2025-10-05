#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int n;
    double average = 0.0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *ptr = (int *)calloc(n, sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Array after calloc: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    printf("Enter %d integers (separated by spaces): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    printf("Updated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ptr[i];
    }
    average = (double)sum / n;

    printf("Average of the array: %.1f\n", average);

    free(ptr);

    return 0;
}
