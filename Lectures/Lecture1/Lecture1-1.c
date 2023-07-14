/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Pipelining, Forks & Parallel Processing:
 * June 13, 2023 Lecture 1-1: Input & Output Operations in C.
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

int globalVar = 10;

int main()
{
    int intVar = 5;
    char charVar = 'a';
    float floatVar = 3.141592;
    char stringVar[12] = "Hello World\n";

    printf("intVar = %d \n", intVar);
    printf("charVar = %c \n", charVar);
    printf("floatVar = %f \n", floatVar);
    printf("stringVar = %s \n", stringVar);

    return 0;
}