#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - function that produces output according to a format
 * @format: character string
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;
	int (*f)(va_list);

	if (!format) /* check if format str == null */
		return (-1); /* return error */

	va_start(args, format);

	while (format[i] != '\0')
	{
		/* if there is a conversion specifier */
		if (format[i] == '%' && format[i + 1])
		{
			i++; /* move to specifier character */
			/* get print function for the conversion specifier */
			f = get_print_func(format[i]);
			if (f == NULL) /* no matching specifer found */
			{
				count += _putchar('%'); /* print literal % */
				count += _putchar(format[i]); /* print the unknown specifier */
			}
			else
			{
				/* call print function and add to count */
				count += f(args);
			}
		}
		else /* normal character to print */
		{
			count += _putchar(format[i]);
		}
		i++; /* go to the next character */
	}

	va_end(args);

	return (count); /* return total number of characters printed */
}
