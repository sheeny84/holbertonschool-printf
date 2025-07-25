#include "main.h"

/**
 * print_char - prints char
 * @args: va_list containing the correct arg
 * Return: number of characters
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}

/**
 * print_str - prints string
 * @args: va_list containing the correct arg
 * Return: number of characters
 */
int print_str(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (!str)
		str = "(null)";

	while (str[i]) /* loop until it hits null terminator */
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * print_percent - print percentage sign
 * @args: va_list containing the correct arg
 * Return: number of characters
 */
int print_percent(va_list args)
{
	(void)args;

	return (_putchar('%'));
}

/**
 * print_int - prints an int (handles both %d and %i)
 * @args: va_list containing the correct arg
 * Return: number of characters
 */
int print_int(va_list args)
{
	int original_num = va_arg(args, int);
	unsigned int abs_num; /* handle digits (always +ve) */
	int divisor = 1; /* hold powers of 10 */
	int count = 0;
	int digit;

	if (original_num < 0)
	{
		_putchar('-');
		count++;
		abs_num = -original_num;
	}
	else
	{
		abs_num = original_num;
	}

	while ((abs_num / divisor) > 9)
	{
		divisor = divisor * 10;
	}

	while (divisor > 0)
	{
		digit = abs_num / divisor;
		_putchar(digit + '0'); /* convert digit to char */
		count++;

		abs_num = abs_num % divisor; /* removes digit just printed */
		divisor = divisor / 10; /* reduce divisor for next digit */
	}
	return (count);
}
