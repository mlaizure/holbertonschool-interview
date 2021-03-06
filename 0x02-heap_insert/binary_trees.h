#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

/**
 * struct next_result - info for next available spot to insert into tree
 *
 * @level: level the node will be added on
 * @p: pointer to spot to add node
 * @parent: pointer to parent of spot to add node
 */

typedef struct next_result
{
	int level;
	binary_tree_t **p;
	binary_tree_t *parent;
} next_res;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
next_res next(binary_tree_t *tree);
binary_tree_t *swap(binary_tree_t *new);

#endif /* BINARY_TREES_H */
