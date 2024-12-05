#include "binary_trees.h"

/**
* heap_extract - Extracts the root node of a Max Binary Heap.
* @root: A double pointer to the root node of heap.
* Return: The value stored in the root node, or 0 on failure.
*/
int heap_extract(heap_t **root)
{
int value;
heap_t *temp;

if (!root || !*root)
return (0);

temp = *root;
value = temp->n;

if (!temp->left && !temp->right)
{
free(temp);
*root = NULL;
}
else
{
heap_t *last_node = max(temp);
(*root)->n = last_node->n;
recurse_extract(*root);
}

return (value);
}

/**
* recurse_extract - Recursively rebalances the heap after extraction.
* @tree: The pointer to the root of the heap.
*/
void recurse_extract(heap_t *tree)
{
heap_t *max_node, *swap_node;

if (!tree || (!tree->left && !tree->right))
return;

if (!tree->right || tree->left->n >= tree->right->n)
max_node = tree->left;
else
max_node = tree->right;

if (max_node->n > tree->n)
{
swap_node = tree;
tree->n = max_node->n;
max_node->n = swap_node->n;
recurse_extract(max_node);
}
}

/**
* max - Finds the last node in level-order traversal.
* @tree: The pointer to the root of the tree.
* Return: Pointer to the last node.
*/
heap_t *max(heap_t *tree)
{
if (!tree->left)
return (tree);

return (tree->right ? max(tree->right) : max(tree->left));
}
