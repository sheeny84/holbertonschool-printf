#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * get_print_func - selects the correct print function based a char
 * @symbol: single char for each type
 *
 * Return: pointer to the print function
 */
int (*get_print_func(char symbol))(va_list)
{
	printer_t printers[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_bin},
		{NULL, NULL}
	};
	int i = 0;

	while (printers[i].symbol != NULL)
	{
		if (symbol == printers[i].symbol[0])
			return (printers[i].f);
		i++;
	}
	return (NULL);
}
