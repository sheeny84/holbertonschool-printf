#include "main.h"
#include <stdarg.h>

/**
 * print_char - function to print the next character arg in a list
 * @args: list of arguments passed into the parent print function
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char x;

	x = va_arg(args, int);
	_putchar(x);
	return (1);
}
