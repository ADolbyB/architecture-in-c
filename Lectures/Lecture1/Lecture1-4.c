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
 * %x - hexadecimal: 0x123A
 * %o - octal
 * %e - scientific notation: 1.2e13
 * %E - scientific notation: 1.2E13
 * %p - memory addresses: a POINTER to a memory address location
 * %% - when you actually need the % sign shown in output :)
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