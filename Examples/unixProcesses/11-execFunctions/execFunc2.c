/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * 
 * Using FIFO files to communicate between processes in C:
 * This example will demonstrate how to execute other programs
 * inside this program with forked processes.
 * 
 * IMPORTANT: If an exec function is called on a PARENT process, then the
 * child process becomes a Zombie process and never gets deallocated.
 * Remember to ONLY call an exec function from the CHILD process.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

#define PING 1
#define MKFIFO 0

int main(int argc, char *argv[])
{
    int pid = fork();
    if(pid == -1)
    {
        printf("Error Forking Process...\n");
        return 10;
    }

    if(pid == 0) // Child Process
    {
        #if PING
            int err = execlp("ping", "ping", "-c", "5", "google.com", NULL);    // Ping Google 10 times
            // Instructions below the exec() function are only carried out if the operation was unsucessful.
            if(err == -1)
            {
                return 11;
            }
        #elif MKFIFO
            int err = execlp("mkfifo", "mkfifo", "sum", NULL);                  // Another Example: Create a FIFO
            // Instructions below the exec() function are only carried out if the operation was unsucessful.
            if(err == -1)
            {
                return 12;
            }
        #endif
        // The child process is REPLACED by the external function 'ping()', therefore
        // Any instructions after the exec function call ARE NOT CARRIED OUT.
        printf("This Should Not Print\n");
    }
    else // Parent Process
    {
        int waitStatus;                                                         // Were All Child Processes Executed Properly?
        wait(&waitStatus);                                                      // Wait for Child Process to Finish.
        if(WIFEXITED(waitStatus))                                               // TRUE (> 0) if good, 0 (FALSE) if there was a problem.
        {
            int statusCode = WEXITSTATUS(waitStatus);                           // Inherits status code from above if functions failed to execute, like a typo in 'ping' command.
            if(statusCode == 0)                                                 // Will inherit status code from the exec() function if (for example) website name 'google.com' has a typo.
            {
                printf("\nSUCCESS!!\n");
            }
            else
            {
                printf("\nFAILED With Status Code %d!!\n", statusCode);
            }
        }
        printf("...Post Processing Functions Go Here...\n\n");
    }

    return 0;
}