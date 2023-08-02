/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * 
 * Named Pipes (FIFOs) in C
 * FIFO is a file type to which we can read or write from any process 
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
    if((mkfifo("myfifo1", 0777)) == -1);        /// 777 for permissions ***
    {
        if(errno != EEXIST)
        {
            printf("Could Not Create FIFO, Exiting...\n");
            return 1;
        }
        else
        {
            printf("FIFO Already Exists...\n");
            return 2;
        }
    }

    printf("FIFO Created...Opening...\n");

    int fd = open("myfifo1", O_WRONLY);
    printf("FIFO Opened...\n");

    int x = 97;
    if(write(fd, &x, sizeof(x)) == -1);
    {
        printf("Error Writing to FIFO, Exiting...\n");
        return 3;
    }

    printf("FIFO Written...\n");
    close(fd);
    
    printf("FIFO Closed...Exiting\n");

    return 0;
}