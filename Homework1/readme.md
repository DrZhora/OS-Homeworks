- Assignment 1: Pointer Basics

p is declared as a pointer to an integer and stores the address of x.
Printing p and &x shows the same address, confirming p points to x.
*p = 10; updates the value of x indirectly.
Observation: A pointer allows modifying a variable’s value without directly using its name.


- Assignment 2: Pointer Arithmetic with Arrays

arr + i points to the i-th element of the array.
*(arr + i) dereferences that address, giving the value.
Adding 2 to each element modifies the array directly via pointers.
Observation: Arrays and pointers are closely related—array indexing is just pointer arithmetic under the hood.


 - Assignment 3: Swapping with Pointers

swap(&a, &b) passes the addresses of a and b.
Inside the function, values at those addresses are swapped.
Observation: Without pointers, swapping inside a function wouldn’t work, since C uses pass-by-value. Pointers enable pass-by-reference behavior.


- Assignment 4: Pointers to Pointers
ptr points to c.
q points to ptr (so it’s a pointer to a pointer).
*ptr gives c, and **q also gives c.
Observation: Multiple levels of indirection are possible. This is useful in dynamic memory (e.g., pointer arrays, double pointers in C).


- Assignment 5: Strings and Character Pointers
str is a character array, and s points to its first element.
Iterating with *(s + i) prints each character.
The loop counts characters until the null terminator \0.
Observation: Strings in C are just arrays of characters, terminated by \0. Pointer iteration makes string traversal easy.