#include "sort.h"

/**
 * sift_down - Performs the sift-down operation to maintain the heap property
 * @array: Pointer to the array.
 * @size_init: Original size of the array.
 * @size: Current size of the array.
 * @i: Index of the root of the tree.
 */
void sift_down(int *array, size_t size_init, size_t size, size_t i)
{
	int n, branch1, branch2;
	size_t br1, br2;

	br1 = i * 2 + 1;
	br2 = br1 + 1;

	/* Check if both branches are within the current size of the array */
	if ((br1 < size) && (br2 < size))
	{
		branch1 = array[br1];
		branch2 = array[br2];

		/* Check which branch is greater and update the root if needed */
		if ((branch1 >= branch2 && branch1 > array[i]) ||
			((br1 == size - 1) && branch1 > array[i]))
		{
			n = array[i];
			array[i] = branch1;
			array[br1] = n;
			print_array(array, size_init);
		}
		else if ((br2 < size) && (branch2 > branch1 && branch2 > array[i]))
		{
			n = array[i];
			array[i] = branch2;
			array[br2] = n;
			print_array(array, size_init);
		}
	}

	/* Recursively apply sift-down to the left and right branches */
	if (br1 < size - 1)
		sift_down(array, size_init, size, br1);
	if (br2 < size - 1)
		sift_down(array, size_init, size, br2);
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm.
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i, size_init = size;
	int n;

	/* Check if the array is valid for sorting */
	if (!array)
		return;

	/* Build a max heap using sift-down */
	for (i = 0; i < size / 2; i++)
	{
		sift_down(array, size_init, size, size / 2 - 1 - i);
	}

	/* Extract elements from the heap and perform sift-down */
	for (i = 0; i < size_init - 1; i++)
	{
		n = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = n;
		print_array(array, size_init);
		sift_down(array, size_init, size - i - 1, 0);
	}
}

