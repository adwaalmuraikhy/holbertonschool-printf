#include "main.h"

/**
 * print_unsigned - prints an unsigned long integer
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_unsigned(unsigned long int n)
{
    int count = 0;

    if (n / 10)
        count += print_unsigned(n / 10);

    count += _putchar((n % 10) + '0');

    return (count);
}
