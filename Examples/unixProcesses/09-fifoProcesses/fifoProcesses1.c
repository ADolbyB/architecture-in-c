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

    int someRand = 0;
    int randomGenerated = 0;
    int i;
    for(i = 0; i < 5; i++)
    {
        someRand = rand();
        randomGenerated = someRand % 100;
        printf("Generated %d\n", randomGenerated);
        myArray[i] = randomGenerated;
    }

    int fd;
    fd = open("sum", O_WRONLY);
    if(fd == -1)
    {
        printf("Error Opening FIFO...Exiting...\n");
        return 1;
    }
    
    int writeVal = 0;
    writeVal = write(fd, myArray, sizeof(int) * 5);             // Write all 5 array indices at the same time (eliminates the for() loop)
    if(writeVal == -1)
    {
        printf("Error Writing To FIFO...Exiting...\n");
        return 2;
    }

    int j;
    for(j = 0; j < 5; j++)
    {
        printf("Wrote: %d \n", myArray[j]);                     // Verify data was written properly
    }
    
    close(fd);
    printf("Writing Closed: Task Finished\n");

    return 0;
}