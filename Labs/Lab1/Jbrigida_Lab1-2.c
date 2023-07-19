/**
 * Joel Brigida
 * CDA4102: Computer Architecture
 * July 13, 2023
 * Pref. Bassem Alhalabi
 * Lab 1-2:
 *      Write a C program that:
 *      - Prompts the user for 6 numbers.
 *      - Scans/Reads those 6 numbers (User Input)
 *      - Calculates: minimum, maximum, average and sum of those numbers.
 *      - Prints results to the screen.
 * 
 * * Note: name, age, salary have different data types.
*/

#include <stdio.h>
#include <string.h>

int main()
{ 
    int numbers[6];
    int i = 0, sum = 0, minimum = 0, maximum = 0;
    double average = 0;
 
    printf("\n\nEnter 6 Integers\n");
    for(i = 0; i < 6; i++) 
    {
        printf("Enter Integer %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    for(i = 0; i < 6; i++)                                              // compute the sum and average 
    {
        sum += numbers[i];                                              // Calculate Sum
    }
    
    double arraySize = (sizeof(numbers) / sizeof(int));                 // get array size
    //printf("arraySize = %0.1lf\n", arraySize);                        // debug

    average = sum / arraySize;                                          // calculate average
    minimum = numbers[0];
    maximum = numbers[0];

    for(i = 0; i < 6; i++)                                              // iterate once to find min & max
    {
        if(numbers[i] < minimum)
        {
            minimum = numbers[i];
        }

        if(numbers[i] > maximum)      
        {
            maximum = numbers[i];
        }
    }

    printf("Sum = %d\n", sum);
    printf("Average = %.3lf\n", average);
    printf("Maximum = %d\n", maximum);
    printf("Minimum = %d\n", minimum);

    return 0;
}