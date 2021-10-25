#include "binary_trees.h"

/**
 * avl_node - creates node for AVL tree
 * @value: data to put in new node
 * Return: AVL node or NULL on failure
 */
avl_t *avl_node(int value)
{
	avl_t *new;

	new = malloc(sizeof(avl_t));
	if (!new)
		return (NULL);

	new->n = value;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;

	return (new);
}

/**
 * generate_avl - generates an AVL tree
 * @array: pointer to first element of array to be converted
 * @prev: pointer to previous node created
 * @start: beginning index of array
 * @end: ending index of array
 * Return: pointer to root node of AVL tree or NULL on failure
 */
avl_t *generate_avl(int *array, avl_t *prev, int start, int end)
{
	avl_t *new;
	int mid = (start + end) / 2;

	if (start > end)
		return (NULL);

	new = avl_node(array[mid]);
	if (!new)
		return (NULL);

	new->parent = prev;
	new->left = generate_avl(array, new, start, mid - 1);
	new->right = generate_avl(array, new, mid + 1, end);
	return (new);
}

/**
 * sorted_array_to_avl - builds an AVL tree from a sorted array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to root node of AVL tree on success, NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size < 1)
		return (NULL);

	return (generate_avl(array, NULL, 0, size - 1));
}
