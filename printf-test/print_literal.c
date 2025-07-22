#include "main.h"
#include <stdarg.h>

/**
 * print_literal - function to print a literal percentage symbol
 * @args: list of arguments passed into the parent print function
 *
 * Return: number of characters printed
 */
int print_literal(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}
