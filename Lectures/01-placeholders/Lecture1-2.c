/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Pipelining, Forks & Parallel Processing:
 * June 13, 2023 Lecture 1-2: Input & Output Operations in C.
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
    int num1, num2;
    printf("Enter 2 Integers: ");
    scanf("%d %d", &num1, &num2);
    printf("\nnum1 = %d, num2 = %d\n", num1, num2);

    char stringVar[12] = "Hello World\n";
    printf("stringVar = %s", stringVar);
    
    printf("Enter a String: ");
    scanf("%s", &stringVar);
    printf("\nstringVar = %s\n", stringVar);

}