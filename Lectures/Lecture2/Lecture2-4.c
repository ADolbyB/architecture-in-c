/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Pipelining, Forks & Parallel Processing:
 * June 13, 2023 Lecture 2-4: fork(), pipe(), & read/write.
 * 
 * C_PLACEHOLDERS:
 * %d - int (same as %i)
 * %ld - long int (same as %li)
 * %f - float
 * %lf, %g - double (long float)
 * %c - char
 * %s - string
 * %x - hexadecimal
 * %p - address
*/

#include <stdio.h>
#include <stdlib.h>                                     // exit() function
#include <string.h>
#include <unistd.h>                                     // Unix processes in C
#include <sys/wait.h>

int main()
{
    int fd[2];
    int pid;
    char buf[10];

    if(pipe(fd) == -1)                                  // create a pipe
    {
        printf("Pipe Error! Exiting...\n");
        exit(1);
    }
    else
    {
        printf("Pipe Created Sucessfully.\n");
    }

    pid = fork();
    if(pid < 0)                                         // Error Condition
    {
        printf("Fork Failed!!! Exiting...\n");
        exit(1);
    }
    else if(pid > 0)                                    // Parent process
    {
        close(fd[0]);                                   // close reading end of pipe
        write(fd[1], "Hello", strlen("Hello") + 1);     // write to the pipe
        wait(NULL);
        close(fd[1]);
    }
    else                                                // child process
    {
        close(fd[1]);                                   // Close writing end of pipe
        read(fd[0], buf, sizeof(buf));                  // Read from the pipe
        printf("Received string: %s\n", buf);
    }

    return 0;
}