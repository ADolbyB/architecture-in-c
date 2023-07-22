/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * C Program to Copy a File into Another File
 * 
 * Code Adapted / Improved from this example: https://www.sanfoundry.com/c-program-copy-file/
 */

#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *readFile; // = fopen("input.txt", "r");
    FILE *writeFile; // = fopen("output.txt", "w");
    
    printf("\n\nFILE pointers created\n");
    
    char ch;
    int pos;
    if ((readFile = fopen("input.txt", "r")) == NULL)
    {
        printf("\n\'input.txt\' cannot be opened...returning\n");
        return 2;
    }
    else
    {
        printf("\n\'input.txt\' opened for copy...\n");
    }
    
    if((writeFile = fopen("output.txt", "w")) == NULL)
    {
        printf("\n\'output.txt\' cannot be opened...returning\n");
        return 2;
    }
    else
    {
        printf("\n\'output.txt\' opened for copy...\n");
    }

    fseek(readFile, 0L, SEEK_END); // file pointer at end of file
    pos = ftell(readFile);
    fseek(readFile, 0L, SEEK_SET); // file pointer set at start

    while (pos--)
    {
        ch = fgetc(readFile);  // copying file character by character
        fputc(ch, writeFile);
    }
    fclose(readFile);
    fclose(writeFile);
    printf("\n\'input.txt\' Copied To: \'output.txt\'\n\n");

    return 0;
}