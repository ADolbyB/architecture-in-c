/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * 
 * This is a tutorial on GDB Debugger.
 * Reference: https://www.youtube.com/watch?v=Dq8l1_-QgAc
 * Ref: https://www.youtube.com/watch?v=MTkDTjdDP3c
 * 
 * command format:
 * `gcc -o [Binary fileName] [Source.c filename] -g`
 * `gcc -o main main.c -g
 * 
 * other useful commands:
 * `wc -c [Binary fileName]`     // shows size of binary file
 * `file [Binary fileName]`      // shows elf-file details (should say 'with debug_info')
 * 
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int d = 2;
    printf("Enter an integer to trigger a crash!! ");
    
    // scanf("%d", d); // crashes
    scanf("%d", &d);

    printf("You Entered %d\n\n", d);

    return 0;
}