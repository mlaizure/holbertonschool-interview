#include <stdlib.h>
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deallocate a binary tree
 *
 * @tree: Pointer to the root of the tree to delete
 */
static void _binary_tree_delete(binary_tree_t *tree)
{
    if (tree)
    {
        _binary_tree_delete(tree->left);
        _binary_tree_delete(tree->right);
        free(tree);
    }
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);

    root->left = binary_tree_node(root, 12);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 16);

    root->right = binary_tree_node(root, 402);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    root->right->right->right = binary_tree_node(root, 402);
    root->right->right->left = binary_tree_node(root->right, 256);
    root->right->left->right = binary_tree_node(root->right, 512);
    root->right->left->left = binary_tree_node(root->right, 512);

    binary_tree_print(root);

    root = swap(root->right);
    binary_tree_print(root);

    struct next_result nx = next(root);
    if (nx.p != &(root->left->left->left))
	    printf("didn't work\n");
    else
	    printf("%p\n", (void*)nx.p);
    printf("before delete\n");
    _binary_tree_delete(root);
    return (0);
}
