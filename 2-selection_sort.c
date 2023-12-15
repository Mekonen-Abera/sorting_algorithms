#include "sort.h"

/**
 * swap_ints - Exchanges the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sorts an array of integers in increasing order
 * @array: An array of integers.
 * @size: The size of the array.
 * By: Mekonen & Gebrekidan
 * Description: Prints the array following a swap in every event.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	/* Check if array is NULL or size is less than 2 */
	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;

		/* Locate the index of the smallest element among the unsorted entries */
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		/* Swap the found minimum value with the first element */
		if (array + i != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
