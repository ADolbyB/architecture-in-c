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
 * 
*/

#include <stdio.h>

int main()
{
    FILE *fPtr;
    int i = 2, j = 3, k = 4;
    int lineNum = 1;
    int n;
    
    fPtr = fopen("../assets/JB1.txt", "w");             // opens 'JB1.txt' in write mode.
    putw(i, fPtr);
    putw(j, fPtr);
    putw(k, fPtr);
    fclose(fPtr);                                       // End writing

    fPtr = fopen("../assets/input.txt", "r");           // Make sure file already exists
    while(getw(fPtr) != EOF)                            // read file line by line
    {
        n = getw(fPtr);
        printf("Line #%d | Value: %d\n", lineNum, n);
        lineNum = lineNum + 1;
    }

    fclose(fPtr);

    return 0;
}