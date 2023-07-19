/**
 * Joel Brigida
 * CDA4102: Computer Architecture
 * July 13, 2023
 * Pref. Bassem Alhalabi
 * Lab 1-1:
 *      Write a C program that:
 *      - prompts the user for: name, age, and salary of 3 employees.
 *      - Scans/Reads: Name, Age, Salary (User Input)
 *      - Prints Information (name, age, salary) of each employee in a separate line.
 * 
 * * Note: name, age, salary have different data types.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int age[3], i, j;
    char name[3][50];
    double salary[3];

    for(i = 0; i < 3; i++)  
    {        
        printf("Enter the name of employee %d (no spaces): ", i + 1);               // prompt the to enter name
        scanf("%s", *&name[i]);                                                     // scan user’s input
        
        printf("Enter the age of employee %d: ", i + 1);                            // prompt the to enter name
        scanf("%d", &age[i]);                                                       // scan user’s input

        printf("Enter the salary of employee %d: ", i + 1);                         // prompt the to enter name
        scanf("%lf", &salary[i]);                                                   // scan user’s input

        printf("\n");                                                               // a new line
    }

    for(j = 0; j < 3; j++)
    {
        // print Prints information (name, age, salary) of each employee in a separate line 

        printf("The name of employee %d is %s. %s is %d years old, and their salary is $%.2f.\n",  j+1, name[j], name[j], age[j], salary[j]); 
    }

    return 0;
} 