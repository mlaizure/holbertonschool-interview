#include "holberton.h"
#include <stdlib.h>

void print_number(int n);
/**
 * main - multiplies two positive numbers
 * @argc: number of arguments from command line
 * @argv: pointer to array of arguments from command line
 *
 * Return: Always 0. Exit status 98 on failure
 */

int main(int argc, char *argv[])
{
	int i, j;
	unsigned long int prod;
	int arg1 = 1;
	int arg2 = 2;

	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	for (i = 1; i < argc; ++i)
	{
		for (j = 0; argv[i][j] != '\0'; ++j)
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				_putchar('E');
				_putchar('r');
				_putchar('r');
				_putchar('o');
				_putchar('r');
				_putchar('\n');
				exit(98);
			}
	}

	prod = atoi(argv[arg1]) * atoi(argv[arg2]);

	print_number(prod);
	_putchar('\n');
	return (0);
}

/**
 * print_number - prints an integer
 * @n: n is the number to print
 *
 * Return: none
 */

void print_number(int n)
{
	if (n / 10 == 0 && n < 0)
		_putchar('-');

	if (n / 10)
		print_number(n / 10);

	if (n % 10 < 0)
		_putchar(-(n % 10) + '0');
	else
		_putchar(n % 10 + '0');

}
