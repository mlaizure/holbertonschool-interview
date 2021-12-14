#include "binary_trees.h"

int check_children(heap_t *node)
{
	if (node->left && node->right)
		return node->right->n > node->left->n;
	else if (node->left)
		return (0);
	else if (node->right)
		return (1);
	else
		return (0);
}

heap_t *heap_rebuild(heap_t **subtree_root)
{
	heap_t *subtree = *subtree_root;

	printf("%d\n", subtree->n);
	if (!subtree->left && !subtree->right)
		return (NULL);
	if (check_children(subtree) == 0)
	{
		subtree->n = subtree->left->n;
		heap_rebuild(&subtree->left);
	}
	else
	{
		subtree->n = subtree->right->n;
		heap_rebuild(&subtree->right);
	}
	return subtree;
}

/**
 * heap_extract - extracts the root node of a max binary heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node or 0 on failure
 */

int heap_extract(heap_t **root)
{
	int root_val = 0;
/*	heap_t *orig_root = *root;*/

	if (!root || !(*root))
		return (0);

	root_val = (*root)->n;
	heap_rebuild(root);
/*	free(orig_root);*/

	return (root_val);
}
