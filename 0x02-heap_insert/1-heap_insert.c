#include "binary_trees.h"

/**
 * find_tree_root - finds root of tree given any node in tree
 * @node: a node in a tree
 * Return: pointer to root
 */

binary_tree_t *find_tree_root(binary_tree_t *node)
{
	while (node->parent)
		node = node->parent;
	return (node);
}


/**
 * swap - swaps values in tree to obtain max heap ordering
 * @new: pointer to node that needs to be sorted
 * Return: pointer to properly sorted new node
 */

binary_tree_t *swap(binary_tree_t *new)
{
	int tmp;

	while (new->parent && new->parent->n < new->n)
	{
		tmp = new->n;
		new->n = new->parent->n;
		new->parent->n = tmp;
		new = new->parent;
	}

	return (new);
}


/**
 * next - finds the next spot to insert in complete binary tree
 * @tree: pointer to root of tree
 * Return: struct containing pointer to the next slot in the tree along
 * with its parent
 */

next_res next(binary_tree_t *tree)
{
	next_res next_left = {0, NULL, NULL},
		next_right = {0, NULL, NULL}, nil = {0, NULL, NULL};

	if (!tree->left)
	{
		next_left.p = &(tree->left);
		next_left.parent = tree;
		return (next_left);
	}
	else if (!tree->right)
	{
		next_right.p = &(tree->right);
		next_right.parent = tree;
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
	heap_t *new = NULL;
	next_res res = {0, NULL, NULL};

	if (!root)
		return (NULL);

	if (!(*root))
	{
		new = binary_tree_node(NULL, value);
		*root = new;
		return (new);
	}

	res = next(*root);
	*(res.p) = binary_tree_node(res.parent, value);
	new = swap(*(res.p));
	*root = find_tree_root(new);
	return (new);
}
