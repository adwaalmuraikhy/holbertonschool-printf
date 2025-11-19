#include "main.h"

/**
 * _printf - Custom printf that handles %c, %s, and %%
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char *str, c;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] != '%')
        {
            write(1, &format[i], 1);
            count++;
        }
        else
        {
            i++;
            if (format[i] == '\0')
            {
                va_end(args);
                return (-1);
            }

            if (format[i] == 'c')
            {
                c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (format[i] == 's')
            {
                str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
            else if (format[i] == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else
            {
                /* Print unknown specifiers as %x */
                write(1, "%", 1);
                write(1, &format[i], 1);
                count += 2;
            }
        }
        i++;
    }

    va_end(args);
    return (count);
}
