#include "sort.h"

/**
 * partition - finds the pivot and divides an array into two partitions
 * with smaller elements on the left, larger elements on the right
 * @array: array to be divided
 * @lo: lower bound of the partition
 * @hi: upper bound of the partition
 * @size: size of the array
 *
 * Return: the pivot point to make the partition
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[hi];
	i = lo - 1;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			if (i < j)
			{
				print_array(array, size);
			}
		}
	}
	i++;
	if (array[i] > pivot)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort - sorts array using Lomuto partition scheme
 * @A: array to be sorted
 * @lo: lower bound of the array
 * @hi: higher bound of the array
 * @size: size of the entire array
 */
void quicksort(int *A, int lo, int hi, size_t size)
{
	int p;

	if (lo >= hi || lo < 0)
		return;

	p = partition(A, lo, hi, size);

	quicksort(A, lo, p - 1, size);
	quicksort(A, p + 1, hi, size);
	/* print_array(A, size); */
	/* quicksort(A, 0, (hi - 1), size); */
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 * Quick Sort Algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quicksort(array, 0, (size - 1), size);
}