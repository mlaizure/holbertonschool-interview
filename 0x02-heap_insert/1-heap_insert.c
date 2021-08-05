#include "binary_trees.h"

void swap(binary_tree_t *tree, binary_tree_t *new)
{
	
}

struct next_result next(binary_tree_t *tree)
{
	struct next_result next_left = {0, NULL}, next_right = {0, NULL};
	struct next_result nil = {0, NULL};

	if (!tree->left)
	{
		next_left.p = &(tree->left);
		return (next_left);
	}
	else if (!tree->right)
	{
		next_right.p = &(tree->right);
		return (next_right);
	}
	else
	{
		next_left = next(tree->left);
		next_left.level++;
		next_right = next(tree->right);
		next_right.level++;
		if (next_left.level <= next_right.level)
			return (next_left);
		else
			return (next_right);
	}
        /* this can't happen. return statement is for compilation purposes */
	return (nil);
}


/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return: pointer to the inserted node or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	if (!root)
		return (NULL);

	if (!(*root))
	{
		new = binary_tree_node(NULL, value);
		*root = new;
		return (new);
	}
	return (NULL);
}
