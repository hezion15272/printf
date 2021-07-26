#include "holberton.h"
/**
 * parser - This function compares the parameters with the arguments and produces an output
 * @format: format string containing the characters and the specifiers
 * @f_list: is a list that contains all types of functions
 * @ap: is a list that contains all the arguments present in the program
 * Return: a total count of the characters printed.
 */
int parser(const char *format, struct convert f_list[], va_list ap)
{
	int i, j, r_val, print_char;

	print_char = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; f_list[j].symbol != NULL; j++)
			{
				if (format[i + 1] == f_list[j].symbol[0])
				{
					r_val = f_list[j].f(ap);
					if (r_val == -1)
						return (-1);
					print_char += r_val;
					break;
				}
			}
			if (f_list[j].symbol == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					print_char = print_char + 2;
				}
				else 
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			print_char++
		}
	}
	return (print_char);
}
