#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending
 * order using the Counting sort algorithm.
 * @array: Pointer to the array.
 * @size: Size of the array.
 **/
void counting_sort(int *array, size_t size)
{
	int max_value, j, *count_array, *aux;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Find the largest value in the array */
	max_value = array[0];
	for (i = 0; i < size; ++i)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	/* Allocate space for the count array */
	count_array = calloc((max_value + 1), sizeof(int));
	if (!count_array)
		return;

	/* Count the number of times each element in the array appears */
	for (i = 0; i < size; ++i)
	{
		count_array[array[i]]++;
	}

	/* Update the count array to indicate the position of each element */
	for (j = 1; j <= max_value; ++j)
	{
		count_array[j] += count_array[j - 1];
	}

	/* Print the count array */
	print_array(count_array, max_value + 1);

	/* Allocate memory for the auxiliary array */
	aux = malloc(sizeof(int) * size);
	if (!aux)
	{
		free(count_array);
		return;
	}

	/* Build the sorted array with the auxiliary array */
	for (i = 0; i < size; ++i)
	{
		count_array[array[i]]--;
		aux[count_array[array[i]]] = array[i];
	}

	/* Copy the sorted elements back to the original array */
	for (i = 0; i < size; ++i)
	{
		array[i] = aux[i];
	}

	/* Free allocated memory */
	free(aux);
	free(count_array);
}
