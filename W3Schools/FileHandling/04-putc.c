/**
 * Joel Brigida
 * CDA4102: Computer Architecture
 * These examples follow the W3Schools "C File Handing" Tutorials.
 * 
 * fopen() modes: r, w, a, r+, w+, a+
 * fclose() closes the file and releases the memory stream.
 * getc() reads a character from a file that has been opened by fopen()
 * putc() writes one character at a time to the FILE pointer.
 * 
*/

#include <stdio.h>

int main()
{
    FILE *fPtr;
    
    char ch;
    fPtr = fopen("../assets/JB1.txt", "wt");        // opens 'JB1.txt' in write mode.
    for(ch = 'D'; ch <= 'S'; ch++)
    {
        putc(ch, fPtr);                             // writes "DEFGHIJKLMNOPQRS" to file.
    }
    fclose(fPtr);

    return 0;
}