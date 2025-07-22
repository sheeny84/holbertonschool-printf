#include "main.h"
#include <stdarg.h>

/**
 * print_str - function to print the next string arg in a list
 * @args: list of arguments passed into the parent print function
 *
 * Return: nothing
 */
void print_str(va_list args)
{
	int i = 0;
	char *str;

	str = va_arg(args, char *);
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
