/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * 
 * Using FIFO files to communicate between processes in C:
 * This example will take an integer as input, then multiply that by 4, and 
 * the output of the fifo will output the result.
 * 
 * From a folder only containing the .c source file:
 * 1) run the `mkfifo sum` command to create a FIFO named 'sum'.
 * 2) 
 * 
 * Compile binary w/ debug symbols & all warnings 
 * gcc -g -Wall -Werror fifo2.c -o fifo2
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int p1[2];
    int pipeVal = pipe(p1);
    if(pipeVal == -1)
    {
        printf("Error Creating Pipe, Exiting...");
        return 1;
    }

    int pid = fork();
    if(pid == -1)
    {
        printf("Error Forking Process, Exiting...");
        return 2;
    }

    if(pid == 0)                    // Child Process
    {

    }
    else                            // Parent Process
    {
        
    }



    return 0;
}