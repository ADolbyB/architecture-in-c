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
 * 
*/

#include <stdio.h>

int main()
{
    char someWel[] = "wel..come";
    char someTo[] = "to";
    int year = 2023;

    FILE *fPtr;    
    fPtr = fopen("../assets/JB1.txt", "w");             // opens 'JB1.txt' in write mode.

    fprintf(fPtr, "%s %s %d", someWel, someTo, year);   // Overwrite file contents in specified format
    fclose(fPtr);

    return 0;
}