#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array for sorting.
 * @size: Size of the array to sort.
 * Done by: Mekonen & gebrekidan
 * Description: It uses a variable gap for sorting subarrays with varying step sizes.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, cmp;
	int temp;

	/* Validations: Check if the array is empty or has only one element */
	if (size < 2)
		return;

	/* Determine the initial gap using the Knuth sequence */
	while (gap < (size / 3))
		gap = gap * 3 + 1;

	/* Compare values at regular intervals determined by the gap */
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			cmp = i;

			/* Compare and swap elements with a gap */
			while (cmp >= gap && array[cmp - gap] > temp)
			{
				array[cmp] = array[cmp - gap];
				cmp -= gap;
				array[cmp] = temp;
			}
		}

		/* Print the current state of the array after each pass */
		print_array(array, size);

		/* Update the gap according to the Knuth sequence */
		gap /= 3;
	}
}

