/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Pipelining, Forks & Parallel Processing:
 * June 13, 2023 Lecture 2-4: fork(), pipe(), & read/write.
*/

#include <stdio.h>
//#include <stdlib.h>                                     // exit() function
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
        return 1;
    }
    else
    {
        printf("Pipe Created Sucessfully.\n");
    }

    pid = fork();
    if(pid < 0)                                         // Error Condition
    {
        printf("Fork Failed!!! Exiting...\n");
        return 2;
    }
    else if(pid > 0)                                    // Parent process
    {
        close(fd[0]);                                   // close reading end of pipe
        write(fd[1], "Hello", strlen("Hello") + 1);     // write to the pipe
        close(fd[1]);
        wait(NULL);                                     // wait for child process to finish
    }
    else                                                // child process
    {
        close(fd[1]);                                   // Close writing end of pipe
        read(fd[0], buf, sizeof(buf));                  // Read from the pipe
        printf("Received string: %s\n", buf);
        close(fd[0]);
    }

    return 0;
}