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
			_putchar(format[i]);
			i++;
			count++;
		}
		else /* i.e. there is a conversion specifier */
		{
			i++; 
			f = get_print_func(format[i]);
			if (f == NULL) 
			{
				_putchar('%');
				_putchar(format[i]);
				count = count + 2;
			}
			else
			{
				count += f(args);
			}
			i++;
		}
	}
	va_end(args);
	return (count);
}
