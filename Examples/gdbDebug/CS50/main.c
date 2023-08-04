/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * 
 * This is a tutorial on GDB Debugger.
 * Reference: https://www.youtube.com/watch?v=sCtY--xRUyI
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

int GetInt(void)
{
    int userInput;
    scanf("%d", &userInput);
    return userInput;
}

int main(int argc, char *argv[])
{
    int num;

    do 
    {
        printf("Enter a Positive Integer to Calculate Factorial: ");
        num = GetInt();
    }
    while (num < 0);

    int factorial;                              // causes implausible output because the value is not defined
    //int factorial = 1;                        // proper declaration and initialization
    for(int i = 1; i <= num; i++)
    {
        factorial = factorial * i;
    }

    printf("%d! = %d\n", num, factorial);

    return 0;
}