/**
 * Joel Brigida
 * CDA4102: Computer Architecture
 * These examples follow the W3Schools "C File Handing" Tutorials.
 * 
 * fopen() modes:
 * 
 * Mode     Description
 * r        It opens an existing text file.
 * w        It opens a text file for writing; a new file is created if the file doesn't exist.
 * a        It opens a text file for appending(writing at the end of an existing file) and creates the file if it does not exist.
 * r+       It opens a text file for reading and writing.
 * w+       It opens a text file for reading and writing, creates the file if it does not exist, and empties it if it already exists.
 * a+       It opens a text file for reading and appending and creates the file if it doesn't exist. Reading starts from the beginning, but writing can only append.
 *  
*/

#include <stdio.h>

int main()
{
    FILE *fPtr;                                     // Declare a pointer to a FILE type.
    fPtr = fopen("../assets/JB1.txt", "w");         // creates 'JB1.txt' in assets folder if it doesn't exist.

    return 0;
}