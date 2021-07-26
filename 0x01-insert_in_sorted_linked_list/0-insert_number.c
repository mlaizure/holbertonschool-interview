#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer to head of singly linked list
 * @number: number to insert into list
 * Return: address of new node or NULL on failure
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current = *head;

	if (!head)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = number;

	if (!current || current->n >= new->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	while (current->next && current->next->n < new->n)
		current = current->next;

	new->next = current->next;
	current->next = new;
	return (new);
}
