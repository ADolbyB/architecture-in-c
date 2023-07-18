/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Pipelining, Forks & Parallel Processing:
 * June 13, 2023 Lecture 2-2: using pid() with fork().
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
#include <stdlib.h>         // exit() function
#include <sys/types.h>
#include <unistd.h>         // Unic processes in C

int main()
{
    int pid;
    pid = fork();

    if(pid < 0)             // error occured
    {
        printf("Fork Failed");
        exit(1);
    }
    else if (pid == 0)      // child process
    {
        printf("I am the child process: pid = %d\n", pid);
    }
    else                    // parent process
    {
        printf("I am the parent process: pid = %d\n", pid);
    }
    sleep(1);

}