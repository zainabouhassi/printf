#include<unistd.h>
/**
 * _putchar - print a character
 * @c: chaacter to print
 *
 * Return: 1
 */
int _putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
