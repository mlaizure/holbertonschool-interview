#include <stdio.h>

/**
 * _strlen_recursion - returns the length of a string
 * @s: string to find the length of
 *
 * Return: length of string
 */

int _strlen_recursion(char *s)
{
	if (!*s)
		return (0);
	else
		return (1 + _strlen_recursion(s + 1));
}

/**
 * is_match - checks if a strings are identical
 * @s1: pointer to first string
 * @st1: start of string 1
 * @s2: pointer to second string
 * @st2: start of string 2
 *
 * Return: 1 if strings are identical, otherwise 0
 */

int is_match(char *s1, int st1, char *s2, int st2)
{
	if (!s1[st1] && !s2[st2])
		return (1);
	if (!s2[st2])
		return (0);

	if (s2[st2] == '*' && !s1[st1])
	{
		return (is_match(s1, st1, s2, st2 + 1));
	}
	else if (s2[st2] == '*')
	{
		if (is_match(s1, st1, s2, st2 + 1))
			return (1);
		else if (is_match(s1, st1 + 1, s2, st2))
			return (1);
		else if (is_match(s1, st1 + 1, s2, st2 + 1))
			return (1);
	}
	else if (s1[st1] == s2[st2])
		return (is_match(s1, st1 + 1, s2, st2 + 1));
	return (0);
}

/**
 * wildcmp - compares two strings and returns 1 if they are identical and
 * otherwise returns 0
 * @s1: first string to be compared
 * @s2: second string to be compared
 *
 * Return: 1 if s1 and s2 are identical, otherwise 0
 */

int wildcmp(char *s1, char *s2)
{
	int n1 = _strlen_recursion(s1);
	int n2 = _strlen_recursion(s2);

	if (n1 == 0 && n2 == 0)
		return (1);
	else
		return (is_match(s1, 0, s2, 0));
}
