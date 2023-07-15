/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Pipelining, Forks & Parallel Processing:
 * June 13, 2023 Lecture 2-3: Visualizing fork().
 * 2 forks create 4 processes, each one prints "Hello World".
 * 
 * Note that 'n' calls to fork() will result in 2^n total processes executing after the last call.
*/

#include <stdio.h>
#include <unistd.h>                     // Unix processes in C

int main()
{
    int id1 = fork();                   // fork() creates 1 child process (2 total)
    int id2 = fork();                   // 2nd fork() forks the now 2 existing child processes (4 total now)
    printf("Hello World!\n");           // All 4 processes execute the "Hello World" printf statement.
    sleep(1);

    return 0;
}