#include "binary_trees.h"

binary_tree_t *findTreeRoot(binary_tree_t *node)
{
	while(node->parent)
		node = node->parent;
	return (node);
}

binary_tree_t *swap(binary_tree_t *new)
{
	int tmp;

	while(new->parent && new->parent->n < new->n)
	{
		tmp = new->n;
		new->n = new->parent->n;
		new->parent->n = tmp;

		/*
		binary_tree_t *old_parent = new->parent;

		if (old_parent->left == new)
		{
			printf("1\n");
			if (new->left)
				new->left->parent = old_parent;
			if (new->right)
				new->right->parent = old_parent;
			if (old_parent->right)
				old_parent->right->parent = new;
			printf("2\n");
			new->parent = old_parent->parent;
			old_parent->parent = new;
			tmp = old_parent->right;
			old_parent->right = new->right;
			new->right = tmp;
			printf("3\n");
			old_parent->left = new->left;
			new->left = old_parent;
			printf("4\n");
		}
		else
		{
			if (new->right)
				new->right->parent = old_parent;
			if (new->left)
				new->left->parent = old_parent;
			if (old_parent->left)
				old_parent->left->parent = new;
			new->parent = old_parent->parent;
			old_parent->parent = new;
			tmp = old_parent->left;
			old_parent->left = new->left;
			new->left = tmp;
			old_parent->right = new->right;
			new->right = old_parent;
		}
		*/
	}

	return findTreeRoot(new);
}

struct next_result next(binary_tree_t *tree)
{
	struct next_result next_left = {0, NULL, NULL},
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
	struct next_result res = { 0, NULL, NULL };

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
	new = *(res.p);
	*root = swap(new);
	return (new);
}
