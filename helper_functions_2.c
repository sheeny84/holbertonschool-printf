#include "main.h"

/**
 * print_bin - prints a binary number
 * @args: va_list containing the correct arg
 * Return: number of characters
 */
int print_bin(va_list args)
{
	int count = 0;
	int dec;

	dec = va_arg(args, int);

	count = print_bin_recursive(dec);

	return (count);
}

/**
 * print_bin_recursive - print binary number using conversion
 * @n: number to print in binary
 * Return: number of characters printed
 */
int print_bin_recursive(int n)
{
	int count = 0;

	if (n > 0)
	{
		count += print_bin_recursive(n / 2);
		count += _putchar((n % 2) + 48);
	}
	return (count);
}
