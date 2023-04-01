#include "main.h"
#include<unistd.h>
/**
 * print_number - function print numbers with recursion
 *
 * @number: input
 * @len: pointer counte the lenght of operration
 *
 * Return: void
 */
void print_number(int number, int *len)
{
	if (number == -2147483648)
	{
		*len += 11;
		write(1, "-2147483648", 11);
		return;
	}
	if (number < 0)
	{
		*len += _putchar('-');
		number *= -1;
	}
	if (number >= 0 && number <= 9)
		*len += _putchar(number + 48);
	else
	{
		print_number(number / 10, len);
		print_number(number % 10, len);
	}
}
