#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct printer - Struct printer
 *
 * @type: The type of variable to print
 * @f: The function associated with that variable type
 */
typedef struct printer
{
	char *type;
	int (*f)(va_list args);
} printer_t;

int _putchar(char c);
int print_char(va_list args);
int print_str(va_list args);
int print_literal(va_list args);
int _printf(const char *format, ...);
int (*get_print_func(char type))(va_list);

#endif
