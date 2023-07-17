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
 * 
*/

#include <stdio.h>
#include <string.h>

void writeToFile(char str[])
{
    FILE* fPtr;                                     // Pointer to file
 
    fPtr = fopen("../assets/JB1.txt", "w");         // Name and mode of the file
 
    fputs(str, fPtr);                               // Write string to file
 
    fclose(fPtr);                                   // Close the file pointer
}

int main()
{
    /** 1st Attempt: Add 2 strings directly **/

    FILE *fp;
    fp = fopen("../assets/JB1.txt", "w");

    fputs("This is a sample text file.\n", fp);
    fputs("This file contains some sample text data.", fp);

    fclose(fp);

    /** 2nd Attempt: Use a Function Call **/

    char str[20];                                   // buffer
    strcpy(str, "This is a DEMO!! ");               // copy string to buffer
    writeToFile(str);                               // Function Call: write to file

    return 0;
}