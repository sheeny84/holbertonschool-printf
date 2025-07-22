#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * get_print_func - selects the correct print function based a char
 * @type: single char for each type
 *
 * Return: pointer to the print function
 */
int (*get_print_func(char type))(va_list)
{
        printer_t printers[] = {
                {"c", print_char},
                {"s", print_str},
		{"%", print_literal},
		{NULL, NULL}
        };
        int i = 0;

        while (printers[i].type != NULL)
        {
                if (type == printers[i].type[0])
                        return (printers[i].f);
                i++;
        }
        return (NULL);
}
