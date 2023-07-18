/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Pipelining, Forks & Parallel Processing:
 * June 13, 2023 Lecture 1-3: Control Structures Review
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

int main ()
{
    int num = 3;
    
    // If-else statements
    if(num == 1)
    {
        printf("Number is 1\n");
    }
    else if (num == 2)
    {
        printf("Number is 2\n");
    }
    else
    {
        printf("Number is not 1 or 2\n");
    }

    // switch statement
    switch(num)
    {
        case 1:
            printf("Number is 1\n");
            break;
        case 2:
            printf("Number is 2\n");
            break;
        default:
            printf("Number is not 1 or 2\n");
            break;
    }
    
    return 0;
}