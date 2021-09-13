#include "palindrome.h"

/**
 * is_pal - recursively divides number and checks against copy
 * @n: number to check
 * @comp_n: copy of number to compare to
 * Return: 1 if n is a palindrome, otherwise 0
 */

int is_pal(unsigned long n, unsigned long *comp_n)
{
	if (n < 10)
	{
		if (n == (*comp_n) % 10)
			return (1);
		else
			return (0);
	}
	if (!is_pal(n / 10, comp_n))
		return (0);
	(*comp_n) /= 10;
	if (n % 10 == (*comp_n) % 10)
		return (1);
	else
		return (0);
	return (0);
}

/**
 * is_palindrome - checks whether a given unsigned int is a palindrome
 * @n: number to check
 * Return: 1 if n is a palindrome, otherwise 0
 */

int is_palindrome(unsigned long n)
{
	unsigned long copy_n = n;
	unsigned long *comp_n = &copy_n;

	if (n < 10)
		return (1);

	return (is_pal(n, comp_n));
}
