/**
 * Joel Brigida
 * CDA4102: Computer Architecture
 * These examples follow the W3Schools "C File Handing" Tutorials.
 * 
 * fopen() modes: r, w, a, r+, w+, a+
 * fclose() closes the file and releases the memory stream.
 * getc() reads a character from a file that has been opened by fopen()
 * 
*/

#include <stdio.h>

int main()
{
    FILE *fPtr = fopen("../assets/JB1.txt", "r");   // opens 'JB1.txt' in read mode.
    int ch = getc(fPtr);
    while(ch != EOF)                                // Display contents of file on the stream
    {
        putchar(ch);                                // Print 1st character of file to screen.
        ch = getc(fPtr);                            // Move to next character.
    }

    if (feof(fPtr))                                 // check if FILE pointer found EOF
    {
        printf("\n___End Of File___");
    }
    else
    {
        printf("\nxxxSome Ting Wong...Couldn't read to EOFxxx");
    }

    fclose(fPtr);
    getchar();                                      // remove '\n' if still in stream.

    return 0;
}