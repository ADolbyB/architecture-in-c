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
 * gcc -g -Wall -Werror fifoProcesses2.c -o fifoProcesses2
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
    int thisArray[5] = { 0 };
    int fd = 0;
    
    fd = open("sum", O_RDONLY);
    if(fd == -1)
    {
        printf("Error Opening FIFO...Exiting...\n");
        return 1;
    }

    int i;
    int readVal;
    for(i = 0; i < 5; i++)
    {
        readVal = read(fd, &thisArray[i], sizeof(int));
        if(readVal == -1)
        {
            printf("Error Reading From FIFO...Exiting...\n");
            return 2;
        }
        printf("Received From FIFO: %d\n", thisArray[i]);
    }

    /* Alternative way to read and eliminate for() loop 
    
    readval = read(fd, thisArray, sizeof(int) * 5)      // Read all 5 array indices at the same time.
    if(readVal == -1)
    {
        printf("Error Reading From FIFO...Exiting...\n");
        return 2;
    }
    // Note that we have to iterate through the array to display values,
    // which defeats the purpose of eliminating the for() loop in the 1st place
    
    */

    close(fd);
    printf("Reading Closed: Performing Sum Operation...\n");

    int sum = 0;
    int j;
    for(j = 0; j < 5; j++)
    {
        sum += thisArray[j];
    }
    printf("The Sum Is: %d", sum);
    printf("\n\n");

    return 0;
}