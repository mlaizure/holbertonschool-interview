#include "lists.h"

int is_pal_rec(listint_t **head, listint_t *start, listint_t *end, int len)
{
	listint_t *current;
	int i;

	if (end->next)
	{
		current = *head;
		for (i = 0; i < len - 1; ++i)
		{
			current = current->next;
		}
		len--;
		printf("current n %d\n", current->n);
		printf("len %d\n", len);
		is_pal_rec(head, current, end->next, len);
	}

	printf("start n %d\n", start->n);
	printf("end n %d\n", end->n);
	if (start->n != end->n)
		return (0);

	return (1);
}

/**
 * is_palindrome - determines if singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	int len = 0;

	if (!head || !(*head))
		return (1);

	while (current)
	{
		current = current->next;
		len++;
	}

	return is_pal_rec(head, *head, *head, len);
}
