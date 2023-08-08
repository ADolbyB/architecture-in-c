/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * 
 * Using FIFO files to communicate between processes in C:
 * This is the first of 2 programs, one that will generate some numbers, and the second one 
 * will read the generates numbers and print out the sum.
 * 
 * From a folder only containing the .c source file:
 * 1) run the `mkfifo sum` command to create a FIFO named 'sum'.
 * 2) 
 * 
 * Compile binary w/ debug symbols & all warnings 
 * gcc -g -Wall -Werror fifoProcesses1.c -o fifoProcesses1
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    int myArray[5] = { 0 };

    int i;
    int someRand = 0;
    int randomGenerated = 0;
    for(i = 0; i < 5; i++)
    {
        someRand = rand();
        randomGenerated = someRand % 100;
        myArray[i] = randomGenerated;
    }

    int fd;
    fd = open("sum", O_WRONLY);
    if(fd == -1)
    {
        printf("Error Opening FIFO...Exiting...\n");
        return 1;
    }
    
    int j;
    int writeVal;
    for(j = 0; j < 5; j++)
    {
        writeVal = write(fd, &myArray[j], sizeof(int));
        if(writeVal == -1)
        {
            printf("Error Writing To FIFO...Exiting...\n");
            return 2;
        }
        printf("Wrote: %d \n", myArray[j]);
    }
    close(fd);
    printf("Writing Closed: Task Finished\n");

    return 0;
}