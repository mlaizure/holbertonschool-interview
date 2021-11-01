#include "search_algos.h"

/**
 * linear_skip - searches for value in sorted skip list of ints
 * @list: pointer to head of list
 * @value: value to search for
 * Return: pointer to first node where value is located or NULL on failure
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t prev = 0;
	skiplist_t *head = list;

	if (!list)
		return (NULL);

	while (list->n < value)
	{
		prev = list->index;
		if (list->express)
			list = list->express;
		else
		{
			while (list->next)
				list = list->next;
			break;
		}
		printf("Value checked at index [%d] = [%d]\n",
		       (int)list->index, list->n);
	}
	printf("Value found between indexes [%d] and [%d]\n",
	       (int)prev, (int)list->index);
	list = head;
	while (list->index < prev)
		list = list->next;
	while (list)
	{
		printf("Value checked at index [%d] = [%d]\n",
		       (int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}
