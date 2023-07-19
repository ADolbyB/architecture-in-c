/**
 * Joel Brigida
 * CDA4102: Computer Architecture
 * July 13, 2023
 * Pref. Bassem Alhalabi
 * Lab 1-4:
 *      Write a C program that:
 *      - Declares a variable and a pointer and assigns a value to the variable.
 *      - Assigns the address of the variable to the pointer.
 *      - Prints the address of the pointer and the value stored.
 *      - Changes the value of the variable.
 *      - Prints the address and the value of the pointer.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int myValue = 41;
    int *myPtr;

    myPtr = &myValue;                                       // Assigns the address of the variable to the pointer 

    printf("\n\nmyPtr points to address: %p\n", myPtr);     // Prints the address of the pointer and the value stored
    printf("Address of myPtr: %p\n", &myPtr);
    printf("Value of myValue: %d\n", myValue);
    printf("Address of myValue: %p\n", &myValue);
    printf("Retrieve myValue by dereferencing myPtr: %d\n", *myPtr);

    myValue = 73;                                           // Changes the value of the variable

    printf("\n\nmyPtr points to address: %p\n", myPtr);     // Prints the address and the value of the pointer
    printf("Address of myPtr: %p\n", &myPtr);
    printf("Value of myValue: %d\n", myValue);
    printf("Address of myValue: %p\n", &myValue);
    printf("Retrieve myValue by dereferencing myPtr: %d\n\n\n", *myPtr);

    return 0;
}