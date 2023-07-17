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
 * 
*/

#include <stdio.h>  
int main()
{  
    /** 1st instance: print only 1st line of file contents **/

    FILE* fileName;                                                     // FILE pointer
    char buf[100];                                                      // Buffer to hold >= 1 line.
    
    fileName = fopen("../assets/JB1.txt", "r");                         // Open Existing File: read mode
    printf("\n\n");                                                     // Add lines when finished.
    
    printf("%s", fgets(buf, 50, fileName));                             // Print file 1st 50 char = 1 line of file contents.
    
    fclose(fileName);                                                   // close reading
    printf("\n\n");                                                     // Add lines when finished.

    /** 2nd instance: print all lines of file content **/

    FILE *fptr;

    fptr = fopen("../assets/JB1.txt", "r");                             // Open a file in read mode
    if(fptr == NULL)
    {
        printf("Not able to open the file.");
        fclose(fptr);
    }

    while(fgets(buf, 100, fptr))                                        // Read the content and print it
    {
        printf("%s", buf);
    }

    fclose(fptr);                                                       // Close the file
    printf("\n\n");                                                     // Add lines when finished.

    /** 3rd Instance: print all lines of file content (alternate: best) **/

    // Open a file in read mode
    fptr = fopen("../assets/JB1.txt", "r");
    if(fptr != NULL)                                                    // If the file exists
    {
        while(fgets(buf, 100, fptr))                                    // Read the content and print it
        {
            printf("%s", buf);
        }   
    }
    else // If the file does not exist
    {
        printf("Not able to open the file.");
    }

    fclose(fptr);                                                       // Close the file
    printf("\n\n\n");

    return 0;
}