/**
 * Joel Brigida
 * CDA4102: Computer Architecture
 * July 13, 2023
 * Pref. BAssem Alhalabi
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
    int numbers[6], i = 0, sum = 0, minimum = 0, maximum = 0;
    double average = 0;
 
    for(i = 0; i < 6; i++) 
    {
        // prompt the to enter a number
        // scan the number
    }
    
    // compute the sum and average                                                                                    

    minimum = numbers[0];                                                // compute the min and max 

    for(i = 0; i < 6; i++)  
    {  
        if(numbers[i] < minimum)
        {
            minimum = numbers[i];
        }      
    }
    
    // compute the min and max                                                                                 
    // print minimum 
    // print maximum 
    // print average 
    // print sum 

    return 0;
}