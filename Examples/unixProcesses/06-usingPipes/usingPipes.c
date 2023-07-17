 /**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Tutorial: Unix Processes in C.
 * Part 6: Communicating between processes with pipes.
 *  Pipes can be written to & read from.
 *  Note that error checking is implemented in this example where possible.
 * 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>                                          // errno & ECHILD macros

int main(int argc, char* argv[])
{
    int id, somePipe;
    int fd[2];                                              // fd[0] = READ, fd[1] = WRITE

    somePipe = pipe(fd);
    if(somePipe == -1);                                     // Open Pipe 1st: File Descriptors are inherited.
    {
        printf("\nError Opening pipe...returning\n\n");
        return 1;
    }

    id = fork();                                            // clone & allocate new memory to an identical child process and run it
    if(id == -1)
    {
        printf("An Error Occurred With The Fork...");
        return 4;
    }
    
    if(id == 0)                                             // CHILD process: WRITE to pipe.
    {
        close(fd[0]);                                       // Close reading end of pipe (we aren't using it);
        int x;
        printf("Input a number: ");
        scanf("%d", &x);
        // x = x * 3;                                       // operate on data before it is sent to the pipe
        if(write(fd[1], &x, sizeof(int)) == -1)
        {
            printf("ERROR Writing to the pipe...returning");
            return 2;
        }
        close(fd[1]);                                       // Close writing end when finished writing.
    }
    else                                                    // Parent Process: READ from pipe
    {
        close(fd[1]);                                       // Close write end: Not using it.
        int y;
        if(read(fd[0], &y, sizeof(int)) == -1)
        {
            printf("Error Reading from the pipe...returning");
            return 3;
        }
        // y = y * 3;                                       // perform data operation before printing to screen.
        close(fd[0]);                                       // Close reading end when done.
        printf("Rec'd from child process: %d\n", y);
    }

    if(id != 0)                                             // Main process
    {
        printf("\n\n");
    }

    return 0;
}