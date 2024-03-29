/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Pipelining, Forks & Parallel Processing:
 * June 13, 2023 Lecture 2-1: the fork() process.
 * 
 * C_PLACEHOLDERS:
 * %d - int (same as %i)
 * %ld - long int (same as %li)
 * %f - float
 * %lf, %g - double (long float)
 * %c - char
 * %s - string
 * %x - hexadecimal: 0x123A
 * %o - octal
 * %e - scientific notation: 1.2e13
 * %E - scientific notation: 1.2E13
 * %p - memory addresses: a POINTER to a memory address location
 * %% - when you actually need the % sign shown in output :)
*/

#include <stdio.h>
#include <unistd.h>                             // Fork & Pipeline methods
#include <sys/types.h>

int main()
{
    /*** 
     * fork() call creates a parallel child process running in tandem with the `main` process, 
     * executing in parallel beside the `main` parent which called it.
     * Therefore: we get 2 "Hello World"s
    */

    fork();
    printf("Hello World\n");

    return 0;
}