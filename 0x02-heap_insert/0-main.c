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

    binary_tree_print(root);

    root->left->n = 700;
    binary_tree_t *a = root;
    binary_tree_t *b = root->left;
    root = swap(root->left);
    if (b->parent)
	    printf("root node has parent\n");
    if (a->parent != b)
	    printf("bad parent\n");
    if (b->left != a)
	    printf("3\n");
    if (b->right != a->right)
	    printf("farts\n");
    printf("before second print\n");
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
