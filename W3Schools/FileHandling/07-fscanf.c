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
 * 
*/

#include <stdio.h>  
int main()
{  
    FILE *f;  
    f = fopen("../assets/JB1.txt", "w");
    fprintf(f, "Reading data from a file is a common feature of file handling.\n");     // prints to file
    fclose(f);                                                                          // close writing
        
    char buf[50];
    f = fopen("../assets/JB1.txt", "r");                                                // Read from file
    printf("\n\n");
    while(fscanf(f, "%s", buf) != EOF)
    {  
        printf("%s ", buf);                                                             // print to screen/terminal each line
    }

    fclose(f);                                                                          // close reading
    printf("\n\n");                                                                     // Add lines when finished.

    return 0;
}