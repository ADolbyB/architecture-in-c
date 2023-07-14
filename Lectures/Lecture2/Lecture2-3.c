/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Pipelining, Forks & Parallel Processing:
 * June 13, 2023 Lecture 2-3: Visualizing fork().
 * 2 forks create 4 processes, each one prints "Hello World".
 * 
 * C_PLACEHOLDERS:
 * %d - int (same as %i)
 * %ld - long int (same as %li)
 * %f - float
 * %lf, %g - double (long float)
 * %c - char
 * %s - string
 * %x - hexadecimal
 * %p - address
*/

#include <stdio.h>
#include <unistd.h>         // Unix processes in C

int main()
{
    int id1 = fork();
    int id2 = fork();
    printf("Hello World!\n");
    sleep(1);

    return 0;
}