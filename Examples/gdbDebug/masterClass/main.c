/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * 
 * This is a tutorial on GDB Debugger.
 * Reference: https://www.youtube.com/watch?v=Dq8l1_-QgAc
 * 
 * bash command format:
 * `gcc -o [Binary fileName] [Source.c filename] -g`
 * `gcc -o main main.c -g
 * 
 * other useful bash commands:
 * `wc -c [Binary fileName]`        // shows size of binary file
 * `file [Binary fileName]`         // shows elf-file details (should say 'with debug_info')
 * `objdump -t ./binaryName`        // Display debug compile symbol table
 * 
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    char *name = "Joel";

    printf("My Name Is: %s\n\n", name);

    return 0;
}