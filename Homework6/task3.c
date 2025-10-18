#include <stdio.h>
#include <stddef.h>
#include <stdalign.h>

struct Unpacked {
    char a;
    int b;
    double c;
};

#pragma pack(push, 1)
struct Packed {
    char a;
    int b;
    double c;
};
#pragma pack(pop)

int main(void) {
    
    struct Unpacked u = { 'x', 12345, 3.14159 };
    struct Packed p = { 'x', 12345, 3.14159 };


    printf("Unpacked struct (normal alignment)\n");
    printf(" sizeof(struct Unpacked) = %zu\n", sizeof(struct Unpacked));
    printf(" &u = %p\n", (void *)&u);
    printf(" &u.a = %p (offset %zu)\n", (void *)&u.a, offsetof(struct Unpacked, a));
    printf(" &u.b = %p (offset %zu)\n", (void *)&u.b, offsetof(struct Unpacked, b));
    printf(" &u.c = %p (offset %zu)\n", (void *)&u.c, offsetof(struct Unpacked, c));
    printf(" distances: b-a = %td bytes, c-b = %td bytes\n",
           (char *)&u.b - (char *)&u.a,
           (char *)&u.c - (char *)&u.b);
    printf("\n");

    printf("Packed struct (#pragma pack(1))\n");
    printf(" sizeof(struct Packed) = %zu\n", sizeof(struct Packed));
    printf(" &p = %p\n", (void *)&p);
    printf(" &p.a = %p (offset %zu)\n", (void *)&p.a, offsetof(struct Packed, a));
    printf(" &p.b = %p (offset %zu)\n", (void *)&p.b, offsetof(struct Packed, b));
    printf(" &p.c = %p (offset %zu)\n", (void *)&p.c, offsetof(struct Packed, c));
    printf(" distances: b-a = %td bytes, c-b = %td bytes\n",
           (char *)&p.b - (char *)&p.a,
           (char *)&p.c - (char *)&p.b);
    printf("\n");



    return 0;
}
