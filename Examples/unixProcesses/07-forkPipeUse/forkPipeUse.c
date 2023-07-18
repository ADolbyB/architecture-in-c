 /**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Tutorial: Unix Processes in C.
 * Part 7: Practical Use Case for fork() & pipe() in C.
 * 
 *  This is a simple use case for multiple processes: To break up a task (like multiple repetitious additions)
 *  into multiple tasks (to take advantage of multicore processors). At the end, both partial sums are added
 *  by one process writing its partial sum to a pipeline, the other process reads that partial sum from the pipeline,
 *  adds it to its own partial sum, and output the Total Sum ONLY ONCE.
 * 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int arr[] = {1, 2, 3, 4, 1, 2, 7, 7};
    int arrSize = sizeof(arr) / sizeof(int);                                    // Result is an integer.
    int start, end;

    int fd[2];                                                                  // fd[0] = read, fd[1] = write;
    if(pipe(fd) == -1)                                                          // Error Handling
    {
        printf("Error Opening Pipe: Returning\n");
        return 1;
    }

    int id;
    id = fork();                                                                // clone & allocate new memory to an identical child process and run it
    if(id == -1)                                                                // Error Handling
    {
        printf("An Error Occurred With The Fork...\n");
        return 2;
    }
    
    if(id == 0)                                                                 // CHILD process: counts lower partial sum: 0 to (arrSize / 2)
    {
        start = 0;
        end = start + (arrSize / 2);                                            // Integer division: result = floor(result);

    }
    else                                                                        // Parent Process: counts upper partial sum: from (arrSize / 2) to arrSize.
    {
        start = arrSize / 2;
        end = arrSize;
    }
    
    int i;
    int sum = 0;
    for(i = start; i < end; i++)                                                // Calculate partial sums in each process
    {
        sum += arr[i];
    }

    if(id == 0)
    {
        printf("Process %d calculated partial sum: %d\n", getpid(), sum);       // debug
        close(fd[0]);                                                           // Close READ: not using it
        if(write(fd[1], &sum, sizeof(sum)) == -1)
        {
            printf("An Error Occurred Writing to the Pipe...\n");
            return 3;
        }
        close((fd[1]));                                                         // Close WRITE when finished.
    }
    else // parent
    {
        printf("\n\nProcess %d calculated partial sum: %d\n", getpid(), sum);   // debug
        close(fd[1]);                                                           // Close WRITE: not using it.
        wait(NULL);                                                             // wait for child process to finish
        
        int sumFromChild;
        if(read(fd[0], &sumFromChild, sizeof(sumFromChild)) == -1)
        {
            printf("An Error Occurred Reading the pipe...\n");
            return 4;  
        }
        close(fd[0]);                                                           // Close READ when done.

        int totalSum;
        totalSum = sum + sumFromChild;                                          // Claculate Total sum
        printf("Total sum = %d\n\n\n", totalSum);
    }

    return 0;
}