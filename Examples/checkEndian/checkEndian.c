/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * 5/22/2023
 * Test Program to check if the machine running code is Little Endian or Big Endian.
*/

#include <stdio.h>

int checkEndianness() 
{
    unsigned int value = 1;                                 // Byte Order: 00 00 00 01
    unsigned char *ptr = (unsigned char *)&value;           // Points to the 1st byte

    return (*ptr == 1) ? 1 : 0;                             // If the 1st byte is '01' it is Little-Endian
}

int main() 
{
    int result;
    result = checkEndianness();

    if (result) // result == 1
    {
        printf("Little-Endian Machine\n");
    }
    else // result == 0
    {
        printf("Big-Endian Machine\n");
    }

    return 0;
}