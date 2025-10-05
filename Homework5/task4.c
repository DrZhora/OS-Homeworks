#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define INITIAL_SIZE 3
#define ADDITIONAL_SIZE 2
#define MAX_STRING_LENGTH 50

int main() {

     
    int total_size = INITIAL_SIZE;

    char **strings = (char **)malloc(INITIAL_SIZE * sizeof(char *));
    if (strings == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d strings: ", INITIAL_SIZE);
    for (int i = 0; i < INITIAL_SIZE; i++) {
        strings[i] = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        if (strings[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(strings[j]);
            }
            free(strings);
            printf("Memory allocation failed!\n");
            return 1;
        }
        scanf("%s", strings[i]);
    }

    strings = (char **)realloc(strings, (INITIAL_SIZE + ADDITIONAL_SIZE) * sizeof(char *));
    
    total_size += ADDITIONAL_SIZE;

    printf("Enter %d more strings: ", ADDITIONAL_SIZE);
    for (int i = INITIAL_SIZE; i < total_size; i++) {
        strings[i] = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
        if (strings[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(strings[j]);
            }
            free(strings);
            printf("Memory allocation failed!\n");
            return 1;
        }
        scanf("%s", strings[i]);
    }

    printf("All strings: ");
    for (int i = 0; i < total_size; i++) {
        printf("%s ", strings[i]);
    }
    printf("\n");


    for (int i = 0; i < total_size; i++) {
        free(strings[i]);
    }
    free(strings);


    return 0;
}
