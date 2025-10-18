#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

int main(void) {
    
    int i = 0;
    char c = 'A';
    double d = 3.14;
    short s = 2;

    printf("Sizes (bytes):\n");
    printf("  int:    %zu\n", sizeof(i));
    printf("  char:   %zu\n", sizeof(c));
    printf("  double: %zu\n", sizeof(d));
    printf("  short:  %zu\n", sizeof(s));

    printf("\nAddresses:\n");
    printf("  &i = %p\n", (void *)&i);
    printf("  &c = %p\n", (void *)&c);
    printf("  &d = %p\n", (void *)&d);
    printf("  &s = %p\n", (void *)&s);

    return 0;
}
