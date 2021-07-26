#include "holberton.h"
/**
 * _printf - Takes input of parameters to print a formated string.
 * Return: A total count of the characters printed
 */
int _printf(const char *format, ...)
{
	int print_char;
	struct convert f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{"R", rot13},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{"%", print_percent},
		{NULL, NULL}
	};
	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format)I;
	/* reference parser(); */
	print_char = parser(format, f_list, ap);
	va_end(ap);
	return (print_char);
}
