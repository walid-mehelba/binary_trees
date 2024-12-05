#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: A double pointer to the root node of the heap.
 * Return: The value stored in the root node, or 0 if the heap is empty.
 */
int heap_extract(heap_t **root)
{
	int value;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	if (!(*root)->left)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	recurse_extract(*root);
	return (value);
}

/**
 * recurse_extract - Recursively adjusts the Max Heap after extraction.
 * @tree: A pointer to the root of the tree.
 */
void recurse_extract(heap_t *tree)
{
	heap_t *sub_max;

	if (!tree || !tree->left)
		return;

	sub_max = max(tree->left);

	if (tree->right)
	{
		heap_t *right_max = max(tree->right);
		if (right_max->n > sub_max->n)
			sub_max = right_max;
	}

	tree->n = sub_max->n;

	if (!sub_max->left && sub_max->parent)
	{
		if (sub_max->parent->left == sub_max)
			sub_max->parent->left = NULL;
		else
			sub_max->parent->right = NULL;

		free(sub_max);
	}
	else
		recurse_extract(sub_max);
}

/**
 * max - Finds the maximum node in a subtree.
 * @tree: A pointer to the root of the subtree.
 * Return: A pointer to the node with the maximum value.
 */
heap_t *max(heap_t *tree)
{
	heap_t *curr_max = tree;

	if (tree->left)
	{
		heap_t *left_max = max(tree->left);
		if (left_max->n > curr_max->n)
			curr_max = left_max;
	}

	if (tree->right)
	{
		heap_t *right_max = max(tree->right);
		if (right_max->n > curr_max->n)
			curr_max = right_max;
	}

	return (curr_max);
}
