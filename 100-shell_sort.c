#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 *               algorithm with the Knuth sequence.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, cmp;
	int temp;

	/* Check if the array is empty or contains only one element */
	if (size == 0 || size == 1)
		return;

	/* Calculate the maximum gap in the Knuth sequence */
	while (gap < (size / 3))
		gap = (gap * 3) + 1;

	/* Compare elements from the beginning and with the gap */
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			cmp = i;

			/* Perform insertion sort within the current gap */
			while (cmp >= gap && array[cmp - gap] > temp)
			{
				array[cmp] = array[cmp - gap];
				cmp -= gap;
				array[cmp] = temp;
			}
		}

		/* Print the current state of the array after each gap */
		print_array(array, size);

		/* Update the gap using the Knuth sequence */
		gap /= 3;
	}
}
