/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Pipelining, Forks & Parallel Processing:
 * June 13, 2023 Lecture 2-4: fork(), pipe(), & read/write.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>                                     // Unix processes in C
#include <sys/wait.h>                                   // needed for wait(NULL)
#include <ctype.h>                                      // isUppper(), toLower(), etc.

int main()
{
    FILE *inputFile = fopen("../Examples/assets/input.txt", "r");   // open file in read mode
    FILE *outputFile = fopen("../Examples/assets/output.txt", "w");

    if(inputFile == NULL || outputFile == NULL)
    {
        printf("ERROR Opening File...Exiting\n\n");
        return 1;
    }

    // Pipe Creation Here: pipe1[2] & pipe2[2]
    
    char pipe1[2];
    char pipe2[2];

    char c;
    while(read(pipe1[0], &c, 1) > 0)
    {
        if(isupper(c))
        {
            c = tolower(c);
        }
        else if(islower(c))
        {
            c = toupper(c);
        }
        write(pipe2[1], &c, 1);
    }

    // remember to close pipes fore each process!!

    return 0;
}