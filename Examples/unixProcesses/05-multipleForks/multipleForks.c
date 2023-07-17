 /**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Tutorial: Unix Processes in C.
 * Part 5: Calling 'fork()' multiple times.
 *  If fork is called multiple times without conditions, then every process will spawn a child process.
 *  for 'n' number of forks: number of total processes = 2^n
 * 
 * Main Process: (id1 != 0 && id2 != 0)
 * ├── Child Process #1: (id1 != 0 && id2 == 0)
 * └── Child Process #2: (id1 == 0 && id2 != 0)
 *     └── Child Process Of Child #2: (id1 == 0 && id2 == 0)
 * 
 * This presents a problem with the wait() function and the MAIN process waiting until BOTH child processes
 * are finished. The solution is in the 'errno.h' library.
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
    int id1, id2;                                           // id = 0 is the CHILD process
    id1 = fork();                                           // clone & allocate new memory to an identical child process and run it
    id2 = fork();

    if(id1 == 0)                                            // ANY CHILD process
    {
        if(id2 == 0)
        {
            printf("Current ID: %d | Parent ID: %d | Child of the 2nd Child process\n", getpid(), getppid());
        }
        else // (id1 == 0 && id2 != 0)
        {
            printf("Current ID: %d | Parent ID: %d | 2nd child of Main process\n", getpid(), getppid());
        }
    }
    else // (id1 != 0)
    {
        if(id2 == 0)
        {
            printf("Current ID: %d | Parent ID: %d | 1st child of Main process\n", getpid(), getppid());
        }
        else // (id1 != 0 && id2 != 0)
        {
            printf("\n\nCurrent ID: %d | Parent ID: %d | MAIN PARENT Process\n\n", getpid(), getppid());    // Should print 1st.
        }
    }

    int result;
    result = wait(NULL);
    if(result == -1)                                            // This method works well in place of 'if(pid != 0)'
    {
        printf("Process %d has no child processes...only leaf nodes return '-1'\n\n", getpid());
    }

    while(wait(NULL) != -1 || errno != ECHILD)                  // FIX for Main process wait() issue.
    {
        printf("Process %d waited for a child process to finish...", getpid());
    }

    if(id1 != 0 && id2 != 0)                                    // Main process
    {
        printf("\n\n");
    }

    return 0;
}