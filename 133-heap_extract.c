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
        heap_t *last_node = max(temp); /* Find last node */
        (*root)->n = last_node->n;    /* Replace root value */
        recurse_extract(*root);       /* Rebalance heap */
    }

    return (value);
}

/**
 * recurse_extract - Recursively rebalances the heap after extraction.
 * @tree: A pointer to the root of the heap.
 */
void recurse_extract(heap_t *tree)
{
    heap_t *max_node;

    if (!tree || (!tree->left && !tree->right))
        return;

    /* Identify the larger child */
    if (!tree->right || (tree->left && tree->left->n >= tree->right->n))
        max_node = tree->left;
    else
        max_node = tree->right;

    /* Swap and recurse if necessary */
    if (max_node && max_node->n > tree->n)
    {
        int temp = tree->n;
        tree->n = max_node->n;
        max_node->n = temp;
        recurse_extract(max_node);
    }
}

/**
 * max - Finds the last node in level-order traversal.
 * @tree: A pointer to the root of the tree.
 * Return: Pointer to the last node.
 */
heap_t *max(heap_t *tree)
{
    if (!tree->left)
        return (tree);

    return (tree->right ? max(tree->right) : max(tree->left));
}
