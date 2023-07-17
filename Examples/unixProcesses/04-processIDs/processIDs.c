 /**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Tutorial: Unix Processes in C.
 * Part 4: Process IDs
 *  getpid(): returns the process ID of running process
 *  getppid(): returns the current process parent's process ID
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int pid;                                // pid = 0 is the CHILD process
    pid = fork();                           // clone & allocate new memory to an identical child process and run it

    if(pid == 0)                            // CHILD process
    {
        //sleep(1);                         // Wait 1 second.
    }

    printf("Current ID: %d | Parent ID: %d\n", getpid(), getppid());

    // if(pid != 0)                         // Parent Processes only
    // {
    //     wait(NULL);                      // Make sure child finishes 1st so it gets deallocated: avoid Zombie Process / Memory leak
    // }

    int result;
    result = wait(NULL);
    if(result == -1)                        // This method works well in place of 'if(pid != 0)'
    {
        printf("No More Child Processes To Wait For...\n");
    }

    return 0;
}