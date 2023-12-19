#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 * Done by: Mekonen & Gebrekidan
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Order a subset of an integer array using Lomuto partition
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The index with which the subset is being ordered
 * @right: The offset end of the subset to sort
 *
 * Return: The final partition index
 */
int lomuto_partition(int array[], unsigned int size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;

	for (above = left, below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implementing an algorithm using recursion, Lomuto’s sort
 * @array: The array of integers that need to be sorted.
 * @size: The size of the array.
 * @left_boundary: The order of the index starts with arrpartition
 * @end_boundary: The last index of the array partition to ordain.
 *
 * Description: Uses the Lomuto partition scheme
 */
void lomuto_sort(int array[], unsigned long size, int left_boundary, int end_boundary)
{
	int part;

	if (end_boundary - left_boundary > 0)
	{
		part = lomuto_partition(array, size, left_boundary, end_boundary);
		lomuto_sort(array, size, left_boundary, part - 1);
		lomuto_sort(array, size, part + 1, end_boundary);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order
 * @array: An array of integers
 * @size: The size of the array
 *
 * Description: Uses the Lomuto partition scheme
 */
void quick_sort(int *array, size_t size)
{
	/* Check if the array is NULL or size is less than 2 */
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

