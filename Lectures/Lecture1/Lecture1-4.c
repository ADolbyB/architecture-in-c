/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Pipelining, Forks & Parallel Processing:
 * June 13, 2023 Lecture 1-5: Pointers in C
 * 
 * C_PLACEHOLDERS:
 * %d - int (same as %i)
 * %ld - long int (same as %li)
 * %f - float
 * %lf, %g - double (long float)
 * %c - char
 * %s - string
 * %x - hexadecimal
*/

#include <stdio.h>

int main()
{
    int x = 42;     // Declare & Initialize an integer variable
    int *xPtr;      // Declare an integer pointer.
    xPtr = &x;      // Assign address of int 'x' to int* 'xPtr'

    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", &x);
    printf("Address pointed to: %p\n", xPtr);
    printf("Address of pointer: %p\n", &xPtr);
    printf("Dereferencing xPtr: %d\n", *xPtr);

    return 0;
}