#include "binary_trees.h"


/**
 * heap_extract - extracts the root node of a max binary heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node or 0 on failure
 */

int heap_extract(heap_t **root)
{
	if (!root || !(*root))
		return (0);

	return ((*root)->n);
}
