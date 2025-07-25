#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len, len2;

    len = _printf("%b\n", 98);
    len2 = printf("%b\n", 98);
    printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    
    _printf("%b\n", -1024);
    printf("%b\n", -1024);
    _printf("%b\n", 0);
    printf("%b\n", 0);
    return (0);
}
