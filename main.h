#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct printer - struct for choosing the right function
 * @spec: format specifier
 * @func: function associated
 */
typedef struct printer
{
	char spec;
	int (*func)(va_list);
} printer_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list ap);
int print_string(va_list ap);
int print_int(va_list ap);
int print_unsigned(unsigned long int n);
int print_binary(va_list ap);

#endif /* MAIN_H */
