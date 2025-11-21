#include "main.h"

/**
 * print_binary - prints an unsigned int in binary (%b)
 * @ap: argument list
 *
 * Return: number of characters printed, or -1 on error
 */
int print_binary(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	char buf[32];
	int i = 0, j, count = 0;

	if (n == 0)
	{
		if (_putchar('0') == -1)
			return (-1);
		return (1);
	}

	while (n > 0)
	{
		buf[i++] = (n & 1) ? '1' : '0';
		n >>= 1;
	}

	for (j = i - 1; j >= 0; j--)
	{
		if (_putchar(buf[j]) == -1)
			return (-1);
		count++;
	}

	return (count);
}
