/**
 * Joel Brigida
 * CDA4102: Computer Architecture
 * July 13, 2023
 * Pref. Bassem Alhalabi
 * Lab 2:
 *      Write a C program that creates 3 processes (1 parent & 2 children). The process will relay information to 
 *      each other in the following fashion:
 *      - The first process (parent) reads a text file "input.txt" line by line.
 *      - The second process reads from the first pipe and reverse letters (Capital to small & small to Capitals).
 *      - The third process reads from the second pipe and outputs to a file e.g. ``output.txt''.
 *      Note that you need to use `pipe()` and `fork()` to create this pipelining assignment. Also, create a text 
 *      file which contains several text lines. The file will be used as an input for your program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <errno.h>
#include <ctype.h>

int main()
{
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "a");

    printf("\n\nFILE pointers created\n");

    if(inputFile == NULL || outputFile == NULL)
    {
        printf("Error opening input or output file...Returning\n");
        return 1;
    }

    int pipe1[2];
    int pipe2[2];
    if(pipe(pipe1) == -1)                                                       // create pipes and check for errors
    {
        printf("Error Opening pipe1: Returning...\n");
        return 2;
    }
    else
    {
        printf("Pipe1 Created...\n");
    }

    if(pipe(pipe2) == -1)
    {
        printf("Error Opening pipe2: Returning...\n");
        return 3;
    }
    else
    {
        printf("Pipe2 Created...\n");
    }

    printf("Both Pipes Created...\n");
    
    int childA, childB;                                                         // Declare both PIDs

    childA = fork();                                                            // Fork first child (2nd Process)
    if(childA == 0)
    {
        printf("Inside 1st Child Process...\n");                                /* Child A Code*/

        close(pipe1[1]);                                                        // close unused pipes
        printf("Child A closed pipe1[1]\n");
        close(pipe2[0]);
        printf("Child A closed pipe2[0]\n");

        char c;
        while(read(pipe1[0], &c, 1) > 0)
        {
            printf("Inside 1st Child While Loop (Read Pipe 1)\n");
            if(islower(c))                                                      // Perform lowercase to uppercase
            {
                c = toupper(c);
            }
            else if(isupper(c))                                                 // Perform uppercase to lowercase
            {
                c = tolower(c);
            }

            if(write(pipe2[1], &c, sizeof(c)) == -1)                            // write back to pipe2
            {
                printf("Error Writing to pipe2[1]...\n");
                return 4;
            }
            else
            {
                printf("Successfully wrote to pipe2\n");
            }
        }
        printf("Data Written To \'pipe2\' Successfully\n");
        close(pipe1[0]);                                                        // Close remaining pipes
        close(pipe2[1]);
    }
    else // Main Parent Branch
    {
        printf("Inside Main Parent Process (Before 2nd Fork)\n");
        
        childB = fork();                                                        // Fork 2nd child (3rd Process)
        if(childB == 0)
        {
            printf("Inside 2nd Child Process...\n");
            /* Child B Code */
            // Close unused pipes
            close(pipe1[1]);
            printf("Child B closed pipe1[1]\n");
            close(pipe2[1]);
            printf("Child B closed pipe2[1]\n");
            char c;
            while(read(pipe2[0], &c, 1) > 0)                                    // Read from pipe2
            {
                // output to file
                printf("Inside 2nd Child While Loop (Print To Output)\n");
                fprintf(outputFile, "%c", c);
            }
            close(pipe2[0]);                                                    // Close unused pipes
            fclose(outputFile);                                                 // Close output file
        }
        else                                                                    // MAIN / Parent Process (1st Process).
        {
            printf("Inside Main Parent Process\n");

            /* Parent Code */
            // Close unused pipes
            close(pipe1[0]);
            close(pipe2[0]);
            char d;
            while(fscanf(inputFile, "%c", &d) == 1)                             // read from inputFile
            {
                if(write(pipe1[1], &d, sizeof(d)) == -1)                        // write to pipe1
                {
                    printf("Error Writing to \'pipe1[1]\'...\n");
                    return 4;
                }
                else
                {
                    printf("Successfully wrote to pipe1\n");
                }
            }
            printf("Data Written to \'pipe1\' Successfully\n");
            close(pipe1[1]);
            fclose(inputFile);
            wait(NULL);
            wait(NULL);
            // close unused pipes
            // close input file
        }
    }
    return 0;
}