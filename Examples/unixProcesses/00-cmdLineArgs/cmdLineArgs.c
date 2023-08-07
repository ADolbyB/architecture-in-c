/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Tutorial: Unix Processes in C.
 * Prereq: How to use command line arguments: `int argc, char* argv[]`
 * 
 * This is code I wrote from following this video (changes mine): 
 * https://www.youtube.com/watch?v=decAHMKIo_A&list=RDCMUC6qj_bPq6tQ6hLwOBpBQ42Q&start_radio=1&rv=decAHMKIo_A
 * 
 * 'argc' = 'Argument Count': How many indices in the argument vector? (Size)
 * 'argv' = 'Argument Vector': The actual command line arguments input by user.
 * 
 * 1) Build binary w/ debug: 'gcc -g -Wall -Werror cmdLineArgs.c -o cmdLineArgs'
 * 2) Launch Binary and include integers as areguments to multiply them all together.
 * 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>                     // strtol() Function

int main(int argc, char* argv[])
{
    int i;
    for(i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    int result = 1;
    for(i = 1; i < argc; i++)
    {
        int x;
        x = strtol(argv[i], NULL, 10);
        result = result * x;
    }
    printf("Multipication Result = %d\n", result);

    return 0;
}