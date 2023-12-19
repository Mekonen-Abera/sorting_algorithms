#include "sort.h"
#include <stdio.h>

/**
 * print_range - Print a range of elements in the array.
 * @array: The array to print.
 * @start: The index with which the range begins.
 * @end: The final index of the range.
 */
void print_range(int *array, int start, int end)
{
	int i;

	for (i = start; i <= end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * swap_elements - Swap two elements of the array according to direction.
 * @array: The array to modify.
 * @i: The first element's index.
 * @j: Second element's index.
 * @dir: The direction of the sorting.
 */
void swap_elements(int *array, int i, int j, int dir)
{
	int tmp;

	if (dir == (array[i] > array[j]))
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

/**
 * bitonic_merge - Sort by swapping and merging elements in the array.
 * @array: The array to sort.
 * @low: The low index of the range to be sorted.
 * @size: How large the range to be sorted.
 * @dir: The direction of sorting.
 * @r_size: The total size of the entire array.
 */
void bitonic_merge(int *array, int low, int size, const unsigned char dir, const int r_size)
{
	int k = size, i = low;

	if (size > 1)
	{
		k = size / 2;

		for (i = low; i < low + k; i++)
			swap_elements(array, i, i + k, dir);

		bitonic_merge(array, low, k, dir, r_size);
		bitonic_merge(array, low + k, k, dir, r_size);
	}
}

/**
 * _bitonic_sort - Recursively segment and sort the array.
 * @array: The array to sort.
 * @low: The lowest index of each band.
 * @size: Range over which to sort.
 * @dir: The direction of sorting.
 * @r_size: The total extent of the array.
 */
void _bitonic_sort(int *array, int low, int size, int dir, const int r_size)
{
	int k = size;

	if (size > 1)
	{
		if (dir == 1)
			printf("Merging [%d/%d] (UP): \n", size, r_size);
		if (dir == 0)
			printf("Merging [%d/%d] (DOWN): \n", size, r_size);
		print_range(array, low, low + k - 1);

		k = size / 2;
		_bitonic_sort(array, low, k, 1, r_size);
		_bitonic_sort(array, low + k, k, 0, r_size);

		bitonic_merge(array, low, size, dir, r_size);
		if (dir == 1)
		{
			printf("Result [%d/%d] (UP): \n", size, r_size);
			print_range(array, low, low + 2 * k - 1);
		}
		if (dir == 0)
		{
			printf("Result [%d/%d] (DOWN): \n", size, r_size);
			print_range(array, low, low + 2 * k - 1);
		}
	}
}

/**
 * bitonic_sort - Calling the sorting function.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;
	const int r_size = (int)size;

	if (size < 2 || !array)
		return;

	_bitonic_sort(array, 0, (int)size, up, r_size);
}
