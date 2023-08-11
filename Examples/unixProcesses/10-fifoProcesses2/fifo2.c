/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * 
 * Using FIFO files to communicate between processes in C:
 * This example will take an integer as input, then multiply that by 4, and 
 * the output of the fifo will output the result. Note that we should NOT 
 * read and write from the same pipe in the same process, or the program
 * may deadlock.
 * 
 * Compile binary w/ debug symbols & all warnings 
 * gcc -g -Wall -Werror fifo2.c -o fifo2
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int p1[2];                                                      // Child To Parent Process (Parent Reads From Child)
    int p2[2];                                                      // Parent to Child Process
    int pipeVal1 = pipe(p1);
    int pipeVal2 = pipe(p2);
    if(pipeVal1 == -1 || pipeVal2 == -1)
    {
        printf("Error Creating Pipe, Exiting...\n");
        return 1;
    }

    int pid = fork();
    if(pid == -1)
    {
        printf("Error Forking Process, Exiting...\n");
        return 2;
    }

    if(pid == 0)                                                    // Child Process
    {
        close(p1[0]);                                               // Don't need to read from child (itself)
        close(p2[1]);                                               // Dont need to write to child (itself)
        int x, pidVal1, pidVal2;
        
        pidVal1 = read(p2[0], &x, sizeof(x));                       // Read pipe data from parent process.
        if(pidVal1 == -1)
        {
            printf("Error Reading Pipe, Exiting...\n");
            return 3;
        }
        else
        {   
            printf("Child: Received \'%d\' From Parent Process.\n", x);
            x *= 4;                                                 // Manipulate data before writing
            
            pidVal2 = write(p1[1], &x, sizeof(x));                  // Write new data to the pipe to be read by parent process.
            if(pidVal2 == -1)
            {
                printf("Error Writing To Pipe (Child), Exiting...\n");
                return 4;
            }
            else
            {
                printf("Child: Wrote New Data \'%d\' To Pipe.\n", x);
                close(p1[1]);
                close(p2[0]);
            }
        }
    }
    else                                                            // Parent Process
    {
        close(p1[1]);                                               // Dont need to write to parent (itself)
        close(p2[0]);                                               // Don't need to read from parent (itself)

        int y, pidVal3, pidVal4;
        srand(time(NULL));
        y = rand() % 25;                                            // Select a random number to send
        
        pidVal3 = write(p2[1], &y, sizeof(y));                      // Write the random number to the pipe to be read by the child process
        if(pidVal3 == -1)
        {
            printf("Error Writing To Pipe (Parent), Exiting...\n");
            return 4;
        }
        else
        {
            printf("\n\nParent: Wrote \'%d\' To Pipe.\n", y);
        }
        
        wait(NULL);                                                 // Wait for child process to finish.
        
        pidVal4 = read(p1[0], &y, sizeof(y));                       // Read manipulated data from child process.
        if(pidVal4 == -1)
        {
            printf("Error Reading Pipe, Exiting...\n");
            return 3;
        }
        else
        {
            printf("Parent: Received Result From Child: %d\n\n", y);
            close(p1[0]);
            close(p2[1]);
        }
    }

    return 0;
}