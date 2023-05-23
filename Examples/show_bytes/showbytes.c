/**
 * Joel Brigida
 * CDA 4102: Computer Architecture
 * 5/22/2023
 * Test Program to display bytes of values in hexadecimal
*/

#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        printf("%.2x", start[i]);
        printf(" ");                    // space in between each byte.
    }
    printf("\n");
}

void show_int(int x)
{
    printf("\n");
    printf("int %d = ", x);
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_long(long x)
{
    printf("\n");
    printf("long %ld = ", x);
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_float(float x)
{
    printf("\n");
    printf("float %f = ", x);
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_double(double x)
{
    printf("\n");
    printf("double %f = ", x);
    show_bytes((byte_pointer) &x, sizeof(double));
}

void show_pointer(void *x)
{
    printf("\n");
    printf("pointer %p = ", x);
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main()
{

    show_int(255);
    show_long(255);
    show_float(255.0);
    show_double(255.0);
    
    int var = 255;
    int *ptr;
    ptr = &var;
    show_pointer(ptr);

    return 0;
}