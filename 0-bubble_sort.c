#include <stdio.h>
#include "sort.h"

/**
 * swap_int - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_int(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble Sort algorithm.
 * @array: Array of integers.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	int swapped = 1;
	size_t i, j = size;

	while (swapped == 1)
	{
		swapped = 0;

		for (i = 1; i < j; ++i)
		{
			if (array[i - 1] > array[i])
			{
				swap_int(&array[i - 1], &array[i]);
				swapped = 1;
				print_array(array, size);
			}
		}

		j--;
	}
}
