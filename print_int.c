#include "main.h"

/**
 * print_number - prints a positive number (recursive)
 * @n: number to print (>= 0)
 *
 * Return: number of characters printed, or -1 on error
 */
static int print_number(unsigned long n)
{
    int count = 0;
    int tmp;

    if (n / 10)
    {
        tmp = print_number(n / 10);
        if (tmp == -1)
            return (-1);
        count += tmp;
    }

    if (_putchar((n % 10) + '0') == -1)
        return (-1);

    return (count + 1);
}

/**
 * print_int - prints a signed integer (%d and %i)
 * @ap: argument list
 *
 * Return: number of characters printed, or -1 on error
 */
int print_int(va_list ap)
{
    int n = va_arg(ap, int);
    long ln = n;
    unsigned long num;
    int count = 0;
    int tmp;

    if (ln < 0)
    {
        if (_putchar('-') == -1)
            return (-1);
        count++;
        ln = -ln;
    }

    num = (unsigned long)ln;

    tmp = print_number(num);
    if (tmp == -1)
        return (-1);

    return (count + tmp);
}
