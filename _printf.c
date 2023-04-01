#include "main.h"
#include<stdarg.h>
#include<stdlib.h>
/**
 * print - check the type of format
 *
 * @c: type we want print them
 * @arg: argument
 * @len: len returned
 *
 * Return: void
 */
void print(char c, va_list arg, int *len)
{
	if (c == '%')
		*len += _putchar('%');
	else if (c == 'c')
		*len += _putchar(va_arg(arg, int));
	else if (c == 's')
		*len += _putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		print_number(va_arg(arg, int), len);
	else if (c == 'b')
		print_binary(va_arg(arg, int), len);
}
/**
 * _printf - code our printf
 *
 * @format: type we want print them
 *
 * Return: lenght
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int i;
	int len = 0;

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(arg);
				return (-1);
			}
			else if (format[i])
				print(format[i], arg, &len);
		}
		else
			len += _putchar(format[i]);
	}
	va_end(arg);
	return (len);
}
