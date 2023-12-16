#include "sort.h"

/**
 * swap_int - Swaps the values of two integers.
 * @a: Pointer to integer a.
 * @b: Pointer to integer b.
 * Done by: Mekonen Abera & Gebrekidan Alemayehu
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: Pointer to an array of integers.
 * @size: The number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
	int swapped = 1;
	size_t i, length = size;

	while (swapped == 1)
	{
		swapped = 0;
		for (i = 1; i < length; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap_int(&array[i - 1], &array[i]);
				swapped = 1;
				print_array(array, size);
			}
		}
		length--;
	}
}

