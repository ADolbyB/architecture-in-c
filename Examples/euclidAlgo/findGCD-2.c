/**
 * Joel Brigida
 * CDA-4201 Computer Architecture
 * 
 * This is an implementation of an Extended Euclidean Algorithm, meaning it
 * DOES solve for the coefficients x & y, where 'ax + by = gcd(a, b)'
 * This is used to calculate the Greatest Common Divisor of 2 numbers.
 * Example Adapted from: https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/#
 * 
*/

#include <stdio.h>
#include <stdlib.h>

int gcdExt(int a, int b, int *x, int *y)    // Calculates the Extended Euclidean Algorithm
{
    if(a == 0)                              // Base Case
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;                             // Stores results of the recursive call
    int gcd = gcdExt(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;                 // Update x & y using results of recursive call
    *y = x1;

    return gcd;
}

int main()
{
    int a = 35, b = 15;
    int x, y = 0;
    int gcd = 1;
    
    // gcd = gcdExt(a, b, &x, &y);
    // printf("GCD(%d, %d) = %d\n", a, b, gcd);

    // a = 35, b = 10;

    // gcd = gcdExt(a, b, &x, &y);
    // printf("GCD(%d, %d) = %d\n", a, b, gcd);

    // a = 31, b = 2;

    // gcd = gcdExt(a, b, &x, &y);
    // printf("GCD(%d, %d) = %d\n\n", a, b, gcd);

    do
    {
        printf("\nEnter 2 Positive Integers separated by a space, and any negative number to exit:  ");
        scanf("%99d %99d", &a, &b);

        if(a > 0 && b > 0)
        {
            gcd = gcdExt(a, b, &x, &y);
            printf("GCD(%d, %d) = %d\n", a, b, gcd);
            printf("x = %d, y = %d\n", x, y);
            printf("ax + by = GCD(a, b)\n");
            printf("(%d * %d) + (%d * %d) = %d\n", a, x, b, y, gcd);
        }

    } while (a > 0 && b > 0);
    
    printf("\nGoodbye!!\n\n");

    return 0;
}