/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * 
 * Named Pipes (FIFOs) in C:
 * A FIFO is a file type to which we can read or write from any process that is open.
 * Here, we create a FIFO named 'myfifo1' and then the program hangs after executing ./namedPipesFIFO
 * Then open up a 2nd terminal, navigate to the directory that contains 'myfifo1' and read the 
 * FIFO by running 'cat myfifo1' The output will be an 'a', which is ASCII 97.
 * Going back to the original terminal where ./namedPipesFIFO was executed, and we see that the
 * process has finished.
 * 
 * Make a FIFO named 'sum':
 * `mkfifo sum`
 * 
 * Compile binary w/ debug symbols & all warnings:
 * gcc -g -Wall -Werror namedPipesFIFO.c -o namedPipesFIFO
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int retval;
    retval = mkfifo("myfifo1", 0777);               // 777 for permissions ***
    if(retval == -1 && errno != EEXIST)
    {
        printf("Could Not Create FIFO, Exiting...\n");
        return 1;
    }

    if(retval < 0)
    {
        printf("FIFO Already Exists...\n");
        return 2;
    }

    printf("FIFO Created...Opening...\n");

    int fd;
    fd = open("myfifo1", O_WRONLY);                 // O_WRONLY: Write Only, O_RDONLY: Read Only, O_RDWR: Read / Write
    if(fd < 0)
    {
        printf("Could Not Open Pipe...Exiting...");
        return 3;
    }
    else
    {
        printf("FIFO Opened...\n");
    }

    int x = 97;                                     // Any value that != NULL to send over FIFO. ASCII 97 = 'a'. 
    int retval2 = 0;
    
    retval2 = write(fd, &x, sizeof(x));
    if(retval2 < 0)
    {
        printf("Error Writing to FIFO, Exiting...\n");
        return 4;
    }

    printf("FIFO Written...\n");

    close(fd);

    printf("FIFO Closed...Exiting...\n");

    return 0;
}