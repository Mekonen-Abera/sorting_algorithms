#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 * Done by: Mekonen & Gebrekidan
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Carries out the partition procedure of Quick Sort.
 * @array: Array to Sort.
 * @low: Index of the low element.
 * @high: Index of the high element.
 * @size: The size of the array for partitioning.
 *
 * Return: Index of the partition.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; ++j)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort2 - Sorts an array of integers in ascending order
 * @array: The array to sort.
 * @low: Index of the low element.
 * @high: Index of the high element.
 * @size: The size of the array to be sorted.
 */
void quick_sort2(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort2(array, low, pivot - 1, size);
		quick_sort2(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Arranges an array of integers in ascending order
 * @array: Array to be sorted.
 * @size: Size of the array to be sorted.
 */
void quick_sort(int *array, size_t size)
{
	int high = size - 1;

	if (size > 1)
		quick_sort2(array, 0, high, size);
}

