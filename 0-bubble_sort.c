#include "sort.h"

/**
* bubble_sort - sorts an array of integers in ascending order using
* Bubble Sort algorithm
* @array: array to be sorted
* @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t temp, i, j;

	if (size <= 1)
		return;

	for (i = 0; i < size; i++)/*iterates throught entire array*/
	{/*iterates & compares elements with the next up to the final element*/
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
