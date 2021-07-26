#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct convert - defines a structure for symbols and functions
 *
 * @symbol: operations signs
 * @func: The functions associated
 */
typedef struct convert
{
	char *symbol;
	int (*func)(va_list);
}convert;

int parser(const char *format, convert f_list[], va_list ap);
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_binary(va_list);
int print_reversed(va_list arg);
int rot13(va_list);
int unsigned_integer(va_list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_heX(va_list list);

#endif /* _HOLBERTON_H_ */
