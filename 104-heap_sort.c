#include "sort.h"

/**
 * swiftdown - Adjusts the heap by swapping elements down the tree.
 * @array: Pointer to the array.
 * @size_init: Original size of the array.
 * @size: Current size of the heap.
 * @i: Index representing the root of the tree.
 */
void swiftdown(int *array, size_t size_init, size_t size, size_t i)
{
	int n, branch1, branch2;
	size_t br1, br2;

	br1 = i * 2 + 1;
	br2 = br1 + 1;

	/* Determine values of branches */
	branch1 = (br1 < size) ? array[br1] : 0;
	branch2 = (br2 < size) ? array[br2] : 0;

	/* Compare and swap if necessary */
	if ((branch1 >= branch2 && branch1 > array[i]) ||
	    (br1 == size - 1 && branch1 > array[i]))
	{
		n = array[i];
		array[i] = branch1;
		array[br1] = n;
		print_array(array, size_init);
	}
	else if (br2 < size && branch2 > branch1 && branch2 > array[i])
	{
		n = array[i];
		array[i] = branch2;
		array[br2] = n;
		print_array(array, size_init);
	}

	/* Recursively check left and right subtrees */
	if (br1 < size - 1)
		swiftdown(array, size_init, size, br1);
	if (br2 < size - 1)
		swiftdown(array, size_init, size, br2);
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i, size_init = size;
	int n;

	/* Check if the array is valid for sorting */
	if (!array || size < 2)
		return;

	/* Build the max heap */
	for (i = size / 2; i > 0; i--)
		swiftdown(array, size_init, size, i - 1);

	/* Heap sort */
	for (i = 0; i < size_init - 1; i++)
	{
		/* Swap the root with the last element and adjust the heap */
		n = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = n;
		print_array(array, size_init);
		swiftdown(array, size_init, size - i - 1, 0);
	}
}

