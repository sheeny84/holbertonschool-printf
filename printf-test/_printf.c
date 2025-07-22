#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * _printf - produce an output according to a format
 * @format: string specifying how to write the output
 *
 * Return: number of characters printed
 */
int _printf(const char * const format, ...)
{
	int i = 0, count = 0;
	int (*f)(va_list);
	va_list args;

	va_start(args, format);
	
	while (format[i] != '\0')
	{
		if (format[i] != '%') /* normal character */
		{
			_putchar(format[i]); /* print character */ 
			count++; /* increase character count */
			i++; /* go to the next char in format */
		}
		else /* i.e. there is a conversion specifier */
		{
			i++; /* get the character after the % symbol */
			/* get print function for the conversion specifier */
			f = get_print_func(format[i]);
			if (f == NULL) /* invalid conversion specifier */ 
			{
				/* print % symbol and character */
				_putchar('%');
				_putchar(format[i]);
				count = count + 2;
			}
			else
			{
				/* call print function and add to count */
				count += f(args);
			}
			i++;
		}
	}
	va_end(args);
	return (count);
}
