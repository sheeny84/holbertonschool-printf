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
	void (*f)(va_list args);
} printer_t;

int _putchar(char c);
void print_char(va_list args);
void print_str(va_list args);
void print_literal(va_list args);
int _printf(const char *format, ...);
void (*get_print_func(char type))(va_list);

#endif
