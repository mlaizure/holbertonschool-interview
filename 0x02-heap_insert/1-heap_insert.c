#include "binary_trees.h"

/**
* binary_tree_height - measures the height of a tree
* @root: root of tree to measure
*
* Return: size of binary tree or 0 on failure
*/
int binary_tree_height(const binary_tree_t *root)
{
	int height = 1;

	while (root->left)
	{
		height++;
		root = root->left;
	}
	return (height);
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
	heap_t *current;

	if (!root)
		return (NULL);

	if (!(*root))
	{
		new = binary_tree_node(NULL, value);
		*root = new;
		return (new);
	}

	height = binary_tree_height(*root);
	printf("%d\n", height);
}
