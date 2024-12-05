#include "binary_trees.h"

/**
* heap_to_sorted_array - Converts a Max Binary Heap to a sorted array.
* @heap: A pointer to the root node of the heap to convert.
* @size: An address to store the size of the array.
* Return: A pointer to the sorted array, or NULL on failure.
*/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
int *array;
int extract, i = 0;
size_t heap_size;

if (!heap || !size)
return (NULL);

heap_size = binary_tree_size(heap);
*size = heap_size;

array = malloc(sizeof(int) * heap_size);
if (!array)
return (NULL);

while (heap)
{
extract = heap_extract(&heap);
array[i++] = extract;
}

return (array);
}
