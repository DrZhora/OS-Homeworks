#include <stdio.h>
#include <stdlib.h>

int main() {

    int numStudents;
    int highest = 0;
    int lowest = 100;  

    printf("Enter the number of students: ");
    if (scanf("%d", &numStudents) != 1 || numStudents <= 0) {
        printf("Invalid number of students!\n");
        return 1;
    }

    int *grades = malloc(numStudents * sizeof(int));
    if (grades == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the grades: ");
    for (int i = 0; i < numStudents; i++) {
        if (scanf("%d", &grades[i]) != 1 || grades[i] < 0 || grades[i] > 100) {
            printf("Invalid grade! Grades must be between 0 and 100.\n");
            free(grades);
            return 1;
        }

        if (grades[i] > highest) {
            highest = grades[i];
        }
        if (grades[i] < lowest) {
            lowest = grades[i];
        }
    }

    printf("Highest grade: %d\n", highest);
    printf("Lowest grade: %d\n", lowest);

    free(grades);

    return 0;
}
