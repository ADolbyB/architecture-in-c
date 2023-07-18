/**
 * Joel Brigida
 * CDA4102: Computer Architecture
 * July 13, 2023
 * Pref. BAssem Alhalabi
 * Lab 2-1:
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
    FILE *input_file = fopen("input.txt", "r");			            // Open input and output files 
    FILE *output_file = fopen("output.txt", "w"); 

    if (input_file == NULL || output_file == NULL)		            // Check if they opened correctly 
    {
        printf("Error opening file");
        return 1;
    }

    int pipe1[2], pipe2[2];					                        // Declare pipe file descriptors 

    // Create both pipes and check for errors 

    int child_a, child_b;				                            // Declare both pids 

    child_a = fork();					                            // Fork first child 
    if(child_a == 0)
    {
        /* Child a code */				                            // Child 1 Code 
        // Close unused pipes

        char c; 
        while(read(pipe1[0], &c, 1) > 0)			                // Read from pipe1 
        { 
            // Perform uppercase to lower, lower to upper conversion 
            // Write back to pipe2 
        }

        // Close remaining pipes

    }
    else
    {							                                    // Parent Process 
        child_b = fork();					                        // Fork second child 
        if (child_b == 0)
        {
            /* Child B code */                                      // Child 2 Code 
            // Close unused pipes

            char c;
            while(read(pipe2[0], &c, 1) > 0)		                // read from second pipe 
            {
                // output to file 
            }
        // Close unused pipes
        // Close output file
        }
        else // Parent Process
        {
            /* Parent code */                                       // Parent Process 

            // Close unused pipes 

            char c;
            while (fscanf(input_file, "%c", &c) == 1)	            // Read from input file 
            { 
                // Write to pipe1.
            }
            // Close unused pipes 
            // Close input file 

            wait(NULL);                                             // Wait for child A to finish 
            wait(NULL);                                             // Wait for child B to finish 
        }

    }

    return 0;
} 