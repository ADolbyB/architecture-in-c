/**
 * Joel Brigida
 * CDA4102: Computer Architecture
 * These examples follow the W3Schools "C File Handing" Tutorials.
 * 
 * fopen() modes: r, w, a, r+, w+, a+
 * fclose() closes the file and releases the memory stream.
 * 
*/

#include <stdio.h>

int main()
{
    FILE *fPtr;                                     // Declare a pointer to a FILE type.
    fPtr = fopen("../assets/JB1.txt", "w");         // creates 'JB1.txt' in assets folder if it doesn't exist.
    
    fprintf(fPtr, "%s", "Custom Text Here...\n");   // 1st line in file
    fprintf(fPtr, "%s", "Your Name HERE!!");        // On 2nd line due to '\n' above
    
    fclose(fPtr);                                   // returns EOF in case of failure, returns 0 on success

    return 0;
}