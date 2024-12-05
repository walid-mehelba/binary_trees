#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array.
 * @heap: A pointer to the root node of the heap to convert.
 * @size: A pointer to store the size of the array.
 * Return: A pointer to the sorted array, or NULL on failure.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t heap_size;
	int i = 0;

	if (!heap || !size)
		return (NULL);

	heap_size = binary_tree_size(heap);
	*size = heap_size;

	array = malloc(heap_size * sizeof(int));
	if (!array)
		return (NULL);

	while (heap)
	{
		array[i++] = heap_extract(&heap);
	}

	return (array);
}
