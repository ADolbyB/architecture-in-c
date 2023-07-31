/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * Review of ENUMs in C Language
 * 
 * Following the example here: 
 */

#include <stdio.h>

enum Color {
    RED,    // 0
    BLUE,   // 1
    YELLOW  // 2
};

typedef enum Color2 {
    RED2 = 7,
    BLUE2,  // 8
    YELLOW2 // 9
} Color2;

int main(int argc, char *argv[])
{
    enum Color c = BLUE;        // enum 'object' declaration w/o typedef
    
    Color2 d = RED2;            // enum 'object' declaration with typedef

    printf("c: %d\n", c);
    printf("d: %d\n", d);

    return 0;
}