#include "main.h"

/**
 * print_number - prints a positive number (recursive)
 * @n: number to print
 *
 * Return: number of characters printed
 */
static int print_number(unsigned long n)
{
    int count = 0;

    if (n / 10)
        count += print_number(n / 10);

    count += _putchar((n % 10) + '0');
    return (count);
}

/**
 * print_int - prints a signed integer (%d and %i)
 * @ap: argument list
 *
 * Return: number of characters printed
 */
int print_int(va_list ap)
{
    int n = va_arg(ap, int);
    unsigned long num;
    int count = 0;
    long ln = n;

    if (ln < 0)
    {
        count += _putchar('-');
        ln = -ln;
    }

    num = (unsigned long)ln;
    count += print_number(num);

    return (count);
}
