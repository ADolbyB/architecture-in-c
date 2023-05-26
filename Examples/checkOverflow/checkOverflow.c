/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * 5/24/2023
 * Test Program to check if an addition and multiplication result will produce overflow.
*/

#include <stdio.h>
#include <limits.h>

int checkAddOverflow(int x, int y)
{
    int sum = x + y;
    int overflow = -1;
    
    if(((x < 0) && (y < 0) && (sum >= 0)) || ((x >= 0) && (y >= 0) && (sum < 0)))
    {
        overflow = 1;
    }
    else
    {
        overflow = 0;
    }

    printf("\nx = %d\n", x);
    printf("y = %d\n", y);
    printf("Sum = %d\n", sum);
    printf("Overflow = %d\n\n", overflow);

    return (overflow);
}

int checkMultOverflow(int x, int y)
{
    int product = x * y;
    int overflow = -1;

    
    if(((x < 0) && (y < 0) && (product >= 0)) || ((x >= 0) && (y >= 0) && (product < 0)))
    {
        overflow = 1;
    }
    else
    {
        overflow = 0;
    }

    printf("\nx = %d\n", x);
    printf("y = %d\n", y);
    printf("Product = %d\n", product);
    printf("Overflow = %d", overflow);

    return (overflow);
}

int main()
{
    short maxShort = SHRT_MAX;
    int maxInt = INT_MAX;
    long maxLong = LONG_MAX;
    printf("\n\nFYI:\nSHRT_MAX = %d\nINT_MAX = %d\nLONG_MAX = %ld\n\n", maxShort, maxInt, maxLong);

    int val1, val2;
    printf("\nEnter 2 integers to check for overflow: ");
    scanf("%d%d", &val1, &val2);

    int addResult, multResult;
    addResult = checkAddOverflow(val1, val2);
    multResult = checkMultOverflow(val1, val2);

    if(addResult == 1)
    {
        printf("\n\n*** Additive Overflow!! ***\n");
    }
    else // if(addResult == 0)
    {
        printf("\n\nNo Additive Overflow.\n");
    }

    if(multResult == 1)
    {
        printf("*** Multiplicative Overflow!! ***\n\n");
    }
    else // if(multResult == 0)
    {
        printf("No Multiplicative Overflow.\n\n");
    }

    return 0;
}