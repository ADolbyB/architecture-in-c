/**
 * Joel Brigida
 * CDA4102: Computer Architecture
 * July 13, 2023
 * Pref. Bassem Alhalabi
 * Lab 1-3:
 *      Write a C program that:
 *      - Takes 2 names.
 *      - Swaps the Names.
 *      - Prints the names before and after swapping.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()  
{ 
    char name1[50];
    char name2[50];
    char temp[50];

    printf("\n\nEnter The First Name (No Spaces): ");
    scanf("%s", *&name1);                                               // scanf() does not read whitespace characters or anything after them

    int ch;     // https://stackoverflow.com/questions/44943622/getchar-function-to-clear-input-buffer-outside-of-while-condition
    while((ch = getchar()) != EOF && ch != '\n');                       // Clear Input Buffer Before Second Name Entered.

    printf("Enter The Second Name (No Spaces): ");
    scanf("%s", *&name2);                                               

    printf("\n\nFirst Name \'name1\': %s\n", name1);
    printf("Second Namd \'name2\': %s\n\n", name2);

    printf("\nName 1 BEFORE swapping: %s, Name 2 BEFORE swapping: %s\n", name1, name2);

    /** Swap Function **/
    strcpy(temp, name1);                                                // copy 'name1' into 'temp'
    strcpy(name1, name2);                                               // copy 'name2' into 'name1'
    strcpy(name2, temp);                                                // copy 'temp' (old 'name1') into 'name2'
    
    printf("Name 1 AFTER swapping: %s, Name 2 AFTER swapping: %s\n\n", name1, name2);

    return 0; 
}