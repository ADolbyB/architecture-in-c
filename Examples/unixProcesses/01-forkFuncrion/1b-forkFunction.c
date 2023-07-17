/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Tutorial: Unix Processes in C.
 * Part 1: The fork() function in C.
 * 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int processCnt;

int main(int argc, char* argv[])
{
    int pid;
    pid = fork();                                   // fork the main() process => 2 processes..
    
    // Note that 2 different pids from the printf statement are shown
    // Child process (the 'new process' we just created) will always be '0'
    // Parent/main process will always be a Positive Integer.
    // A value of '-1' represents an error in creating the process.

    if(pid == 0) // Child process
    {
        printf("IF: Hello From The Child Process: %d\n", pid);
    }
    else // pid != 0 (main process)
    {
        fork();                                     // 2nd fork creates 3rd process from main/parent
        printf("ELSE: Hello From The Main Process: %d\n", pid);
    }

    // 3 processes run the "Hello World from pid: %d\n" printf() statement.
    // Therefore the statement prints 3 times upon code execution.
    printf("MAIN: Hello from pid: %d\n", pid);

    return 0;
}