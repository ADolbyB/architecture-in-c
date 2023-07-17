/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Tutorial: Unix Processes in C.
 * Part 1: The fork() function in C.
 * 
 * This is code I wrote from following the YouTube Series: 
 * https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY
 * 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int pid;
    pid = fork();
    printf("Hello World from pid: %d\n", pid);
    /** Note that 2 different pids from the printf statement are shown **/
    // Child process (the 'new process' we just created) will always be '0'
    // Parent/main process will always be a Positive Integer.
    // A value of '-1' represents an error in creating the process.

    if(pid == 0)
    {
        printf("Hello From The Child Process: %d\n", pid);
    }
    else
    {
        printf("Hello From The Main Process: %d\n", pid);
    }

    return 0;
}