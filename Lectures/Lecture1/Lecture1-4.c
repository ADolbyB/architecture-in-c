/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Pipelining, Forks & Parallel Processing:
 * June 13, 2023 Lecture 1-4: For & While Loop Review
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
    int i, j;

    // for() loop
    printf("Using for() loop:\n");
    for(i = 1; i <= 5; i++)
    {
        printf("Iteration %d\n", i);
    }
    printf("\n");

    // While Loop
    printf("Using while loop:\n");
    j = 1;
    while(j <= 5)
    {
        printf("Iteration %d\n", j);
        j++;
    }

    return 0;
}