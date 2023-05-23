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

void test_show_bytes(int val)
{
    int ival = val;
    long lval = (long)ival;
    float fval = (float)ival;
    int *pval = &ival;
    show_int(ival);
    show_long(lval);
    show_float(fval);
    show_pointer(pval);
}

int main()
{

    test_show_bytes(255);

    return 0;
}