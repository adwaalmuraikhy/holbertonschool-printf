#include "main.h"

/**
 * print_binary - prints an unsigned int in binary
 * @ap: argument list
 *
 * Return: number of characters printed, or -1 on error
 */
int print_binary(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	char buf[32];
	int i = 0, count = 0;

	if (n == 0)
	{
		if (_putchar('0') == -1)
			return (-1);
		return (1);
	}

	/* store bits in reverse order */
	while (n > 0)
	{
		buf[i++] = (n & 1) ? '1' : '0';
		n >>= 1;
	}

	/* print from last to first */
	while (i > 0)
	{
		i--;
		if (_putchar(buf[i]) == -1)
			return (-1);
		count++;
	}

	return (count);
}
