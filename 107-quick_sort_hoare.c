#include "sort.h"

/**
 * swap - Swaps the positions of two elements in an array.
 * @array: The array.
 * @item1: Index of the first element
 * @item2: Index of the second element
 * Done by: Mekonen & Gebrekidan
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * hoare_partition - Implements the Hoare partition sorting scheme.
 * @array: The array.
 * @first: Index of the first element.
 * @last: Index of the last element.
 * @size: Size of the array.
 * Return: Position of the last element after sorting.
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{
		do {
			current++;
		} while (array[current] < pivot);

		do {
			finder--;
		} while (array[finder] > pivot);

		if (current >= finder)
			return (current);

		swap(array, current, finder);
		print_array(array, size);
	}
}

/**
 * quick_sorting - Implements the quick sorting algorithm.
 * @array: The array.
 * @first: Index of the first element.
 * @last: Index of the last element.
 * @size: Size of the array.
 */
void quick_sorting(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		quick_sorting(array, first, position - 1, size);
		quick_sorting(array, position, last, size);
	}
}

/**
 * quick_sort_hoare - Prepares the terrain for the quicksort algorithm
 * @array: The array.
 * @size: Size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sorting(array, 0, size - 1, size);
}

