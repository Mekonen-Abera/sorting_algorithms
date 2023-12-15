#include "sort.h"

/**
 * swap - Switches the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sorts an array using the selection-Sort algorithm.
 * @array: Input array to sort.
 * @size: Dimension of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	/* Ensure that the array has fewer than two elements */
	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		/* Get the min index of the unsorted part */
		for (j = i + 1; j < size; j++)
		{
			if (array[min_index] > array[j])
				min_index = j;
		}

		/* Exchange the discovered minimum element with the first element */
		if (min_index != i)
		{
			swap(&array[min_index], &array[i]);
			print_array(array, size);
		}
	}
}

