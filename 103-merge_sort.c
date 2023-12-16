#include "sort.h"
#include <stdio.h>

/**
 * merge - Merges left and right arrays into the original array.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @left: Pointer to the left array.
 * @right: Pointer to the right array.
 */
void merge(int *array, int *left, int *right, size_t size)
{
	size_t i = 0, j = 0, k = 0;
	size_t size_left, size_right;

	size_left = size / 2;
	size_right = size - size_left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);

	while (i < size_left && j < size_right)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < size_left)
		array[k++] = left[i++];

	while (j < size_right)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = 0, i;
	int left[1000];
	int right[1000];

	/* Check if the array is valid for sorting */
	if (!array || size < 2)
		return;

	mid = size / 2;

	/* Populate left and right arrays */
	for (i = 0; i < mid; i++)
		left[i] = array[i];

	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	/* Recursively apply merge sort to left and right arrays */
	merge_sort(left, mid);
	merge_sort(right, size - mid);

	/* Merge the sorted left and right arrays back into the original array */
	merge(array, left, right, size);
}

