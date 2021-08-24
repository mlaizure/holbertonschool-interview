#include "lists.h"

/**
 * is_palindrome - determines if singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t *current = *head, *start = *head, *end = *head;
	int len = 0, i = 0, j = 0;

	if (!head || !(*head))
		return (1);

	while (current)
	{
		current = current->next;
		len++;
	}
	printf("len %d\n", len);
	for (i = 0; i < len / 2; ++i)
	{
		j = i + 1;
		end = *head;
		while (j < len)
		{
			end = end->next;
			++j;
		}
		if (start->n != end->n)
			return (0);
		start = start->next;
	}

	return (1);
}
