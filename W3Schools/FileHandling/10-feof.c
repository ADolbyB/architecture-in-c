/**
 * Joel Brigida
 * CDA4102: Computer Architecture
 * These examples follow the W3Schools "C File Handing" Tutorials.
 * 
 * fopen() modes: r, w, a, r+, w+, a+
 * fclose() closes the file and releases the memory stream.
 * getc() reads a character from a file that has been opened by fopen()
 * putc() writes one character at a time to the FILE pointer.
 * putw() writes 1 line at a time to the FILE pointer.
 * getw() reads 1 line at a time from the FILE pointer.
 * fprintf() prints a specific format to the file
 * fscanf() reads input from a file.
 * fgets() reads files 1 line at a time.
 * fputs() writes strings to file directly 1 line at a time
 * feof() determines if the EOF has been reached or not.
 * 
*/

#include <stdio.h>

int main()
{
    FILE *fPtr = NULL; 
    char buf[50]; 
    
    fPtr = fopen("../assets/JB1.txt","r");                          // Open file in read mode
    if(fPtr)                                                        // If file exists: if(fPtr != NULL)
    { 
        while(!feof(fPtr)) 
        { 
            fgets(buf, sizeof(buf), fPtr); 
            puts(buf);                                              // something inserts an extra '\n' at the terminal printout
        } 
        fclose(fPtr); 
    }
    else
    {
        printf("Can't Open File...");
    }

    return 0;
}