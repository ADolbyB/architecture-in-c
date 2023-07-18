 /**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Tutorial: Unix Processes in C.
 * Part 7: Practical Use Case for fork() & pipe() in C.
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
    int fd[2];                                              // fd[0] = read, fd[1] = write;
    if(pipe(fd) == -1)
    {
        printf("Error Opening Pipe: Returning\n");
        return 1;
    }

    int id;
    id = fork();                                            // clone & allocate new memory to an identical child process and run it
    if(id == -1)
    {
        printf("An Error Occurred With The Fork...\n");
        return 4;
    }
    
    if(id == 0)                                             // CHILD process: WRITE to pipe.
    {
        close(fd[0]);                                       // Close reading end of pipe (we aren't using it);
        int x;
        printf("Input a number: ");
        scanf("%d", &x);
        // x = x * x;                                       // (x^2) operate on data before it is sent to the pipe (OPTIONAL)
        if(write(fd[1], &x, sizeof(int)) == -1)
        {
            printf("ERROR Writing to the pipe...returning\n");
            return 2;
        }
        close(fd[1]);                                       // Close writing end when finished writing.
        printf("Child Sent %d to the pipe\n", x);
    }
    else                                                    // Parent Process: READ from pipe
    {
        close(fd[1]);                                       // Close write end: Not using it.
        int y;
        printf("Parent Process Waiting...\n");
        wait(NULL);                                         // Wait for child process to finish w/ User Input
        
        if(read(fd[0], &y, sizeof(int)) == -1)
        {
            printf("Error Reading from the pipe...returning\n");
            return 3;
        }
        // y = y * 3;                                       // (3y) perform data operation before printing to screen (OPTIONAL).
        close(fd[0]);                                       // Close reading end when done.
        printf("Main Process rec'd from child process: %d\n", y);
    }

    if(id != 0)                                             // Main process
    {
        printf("\n\n");
    }

    return 0;
}