#include "holberton.h"

/**
 * print_reversed - Calls a function to reverse and print a string
 * @arg: Argument passed to the function
 * Return: The amount of characters printed
 */
int print_reversed(va_list arg)
{
	int len;
	char *str;
	char *ptr;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (-1);
	ptr = rev_string(str);
	if (ptr == NULL)
		return (-1);
	for (len = 0; ptr[len] != '\0'; len++)
		_putchar(ptr[len]);
	free(ptr);
	return (len);
}

/**
 * rot13 - Converts string to rot13
 * @list: string to convert
 * Return: converted string
 */
int rot13(va_list list)
{
	int i;
	int x;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(list, char *);
	if (str == NULL)
		return (-1);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (x = 0; x <= 52; x++)
		{
			if (str[i] == s[x])
			{
				_putchar(u[x]);
				break;
			}
		}
		if (x == 53)
			_putchar(str[i]);
	}
	return (i);
}

/**
 * hex_print - prints a char's ascii value in uppercase hex
 * @c: char to print
 *
 * Return: number of chars printed (always 2)
 */
static int hex_print(char c)
{
	int count;
	char diff = 'A' - ':';
	char d[2];

	d[0] = c / 16;
	d[1] = c % 16;
	for (count = 0; count < 2; count++)
	{
		if (d[count] >= 10)
			_putchar('0' + diff + d[count]);
		else
			_putchar('0' + d[count]);
	}
	return (count);
}

/**
 * print_S - prints a string and nonprintable character ascii values
 * @S: string to print
 *
 * Return: number of chars printed
 */
int print_S(va_list S)
{
	unsigned int i;
	int count = 0;
	char *str = va_arg(S, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count += hex_print(str[i]);
		}
		else
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}
