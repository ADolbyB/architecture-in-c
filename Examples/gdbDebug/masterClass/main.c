/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * 
 * This is a tutorial on GDB Debugger.
 * Reference: https://www.youtube.com/watch?v=Dq8l1_-QgAc
 * 
 * bash command format:
 * `gcc -o [Binary fileName] [Source.c filename] -g`
 * `gcc -o main main.c -g'
 * 
 * To debug & enable all warnings at compilation time:
 * `gcc -g -Wall -Werror main.c -o main`
 * 
 * other useful bash commands:
 * `wc -c [Binary fileName]`        // shows size of binary file
 * `file [Binary fileName]`         // shows elf-file details (should say 'with debug_info')
 * `objdump -t ./binaryName`        // Display debug compile symbol table
 * 
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *name = "Joel";
    char *name2 = "Brigida";

    printf("My Name Is: %s\n\n", name);

    name = name2;

    printf("My Name Is: %s\n\n", name2);

    return 0;
}