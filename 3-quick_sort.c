#include "sort.h"

/**
 * swap - swap two items
 * @a: Int
 * @b: Int
 */

void swap(int *a, int *b)
{
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

/**
 * partition - exceutes the partition process
 * @array: pointer to array to sort
 * @low: index of the low element
 * @high: index of the high element
 * @size: size of array for partitioning
 * Return: index o the partition
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1), j;

	for (j = low; j <= high - 1; j++)
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
 * quick_sort2 - sorts an array of integers in ascending order
 * using Quick Sort algorithm
 * @array: pointer to array to sort
 * @low: index of the low element
 * @high: index of the high element
 * @size: size of array to sort
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
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: pointer to array to sort
 * @size: size of array to sort
 */

void quick_sort(int *array, size_t size)
{
	int high = size - 1;

	if (size > 1)
		quick_sort2(array, 0, high, size);
}
