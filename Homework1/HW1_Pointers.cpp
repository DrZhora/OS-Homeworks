#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main() {

    // Asignment 1
    printf("--Asignment 1---\n");
    int x = 6;
    int *p = &x;   // p is a pointer to an int 
    printf("%p\n", p);
    printf("%p\n", &x ); 

    *p = 10;      
    printf("%d\n", *p);


    // Asignment 2
    printf("--Asignment 2---\n");
    int arr[5] = {1,2,3,4,5};
    
    for (int i=0; i<5;i++){
        printf("%d\n", *(arr + i));
    }

    for (int i=0; i<5;i++){
        *(arr + i) += 2;
    }
    
    printf("Modified array\n");
    // for (int i=0; i<5;i++){
    //     printf("%d\n", *(arr + i));
    // }
    for (int i=0; i<5;i++){
        printf("%d\n", arr[i]);
    }

    // Asignment 3
    printf("--Asignment 3---\n");
    
    int a = 5;
    int b = 10;
    printf("a: %d, b: %d\n", a, b);
    swap(&a, &b);
    printf("a: %d, b: %d\n", a, b);



    // Asignment 4
    printf("--Asignment 4---\n");
    int c = 7;
    int *ptr = &c;
    int **q = &ptr;
    printf("%d\n", *ptr);
    printf("%d\n", **q);

    // Asignment 5
    printf("--Asignment 5---\n");
    char str[] = "Hello";
    char *s = str;
    for (int i=0; i<5;i++){
        printf("%c", *(s + i));
    }
    
    int num_of_chars = 0;
    while (*s != '\0'){
        num_of_chars++;
        s++;
    }
    printf("\nNumber of characters: %d\n", num_of_chars);   

}



