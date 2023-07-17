 /**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Tutorial: Unix Processes in C.
 * Part 2: Waiting for processes to finish
 *  This program uses 2 processes to print the numbers 1 - 10 to the terminal.
 *  The child process prints the first numbers 1, 2, 3, 4, 5.
 *  The Main/Parent process prints the 2nd set of numbers 6, 7, 8, 9, 10.
 * 
 *  Note that without the 'fflush()' command, since stdout has an internal buffer, when
 *  a bunch of items are printed to it quickly, it will wait and fill some of the buffer,
 *  then print it to the screen.
 * 
 * wait(): tells the main process to wait at that step until the child process has finished executing to the END.
 * 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int pid, i, n;                          // n = numbers 1 through 10 for counting / displaying to user.
    pid = fork();                           // clone & allocate new memory to an identical child process and run it

    if(pid == 0)                            // Child process prints 1 - 5
    {
        n = 1;
    }
    else                                    // Main Process prints 6 - 10
    {
        n = 6;
    }

    if(pid != 0)                            // Tell the main process to wait until child process prints '1 - 5'
    {
        wait();                             // Main: wait until the child process finishes. This function helps order the execution of processes
    }

    for(i = n; i < (n + 5); i++)
    {
        printf("%d  ", i);
        fflush(stdout);                     // display each number to screen individually with each 'printf()' call.
    }
    
    if(pid != 0)                            // Only print the newlines after the main process finishes
    {
        printf("\n\n");
    }

    return 0;
}