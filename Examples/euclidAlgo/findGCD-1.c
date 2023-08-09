/**
 * Joel Brigida
 * CDA-4201 Computer Architecture
 * 
 * This is an implementation of a Basic Euclidean Algorithm, meaning it
 * does not solve for the coefficients x & y, where 'ax + by = gcd(a, b)'
 * This is used to calculate the Greatest Common Divisor of 2 numbers.
 * Example Adapted from: https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/#
 * 
*/

#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)   // Function Returns the GCD of a & b
{
    if(a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

int main()
{
    int a = 10, b = 15;

    // printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));

    // a = 35, b = 10;

    // printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));

    // a = 31, b = 2;

    // printf("GCD(%d, %d) = %d\n\n", a, b, gcd(a, b));

    do
    {
        printf("\nEnter 2 Positive Integers separated by a space, and any negative number to exit:  ");
        scanf("%99d %99d", &a, &b);

        if(a > 0 && b > 0)
        {
            printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));
        }

    } while (a > 0 && b > 0);
    
    printf("\nGoodbye!!\n\n");

    return 0;
}