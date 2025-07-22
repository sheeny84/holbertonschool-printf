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
	int i = 0;
	void (*f)(va_list);
	va_list args;

	va_start(args, format);
	
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			i++;
		}
		else /* i.e. there is a conversion specifier */
		{
			i++; 
			f = get_print_func(format[i]);
			if (f == NULL) 
			{
				_putchar('%');
				_putchar(format[i]);
			}
			else
			{
				f(args);
			}
			i++;
		}
	}
	return (0);
}
