#include <stdio.h>
#include <stddef.h>

struct S1 {
    char a;
    int b;
    double c;
};

struct S2 {
    double c;
    int b;
    char a;
};

int main(void) {
    struct S1 s1 = { 'x', 12345, 3.14159 };
    struct S2 s2 = { 3.14159, 12345, 'x' };

    printf("struct S1 (char a; int b; double c;)\n");
    printf(" sizeof(S1) = %zu\n", sizeof(struct S1));
    printf(" &s1        = %p\n", (void *)&s1);
    printf(" &s1.a      = %p (offset %zu)\n", (void *)&s1.a, offsetof(struct S1, a));
    printf(" &s1.b      = %p (offset %zu)\n", (void *)&s1.b, offsetof(struct S1, b));
    printf(" &s1.c      = %p (offset %zu)\n", (void *)&s1.c, offsetof(struct S1, c));
    printf(" distances: b-a = %td bytes, c-b = %td bytes\n",
           (char *)&s1.b - (char *)&s1.a,
           (char *)&s1.c - (char *)&s1.b);
    printf("\n");

    printf("struct S2 (double c; int b; char a;)\n");
    printf(" sizeof(S2) = %zu\n", sizeof(struct S2));
    printf(" &s2        = %p\n", (void *)&s2);
    printf(" &s2.c      = %p (offset %zu)\n", (void *)&s2.c, offsetof(struct S2, c));
    printf(" &s2.b      = %p (offset %zu)\n", (void *)&s2.b, offsetof(struct S2, b));
    printf(" &s2.a      = %p (offset %zu)\n", (void *)&s2.a, offsetof(struct S2, a));
    printf(" distances: b-c = %td bytes, a-b = %td bytes\n",
           (char *)&s2.b - (char *)&s2.c,
           (char *)&s2.a - (char *)&s2.b);
    printf("\n");


    return 0;
}
