#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array.
 * @size: Size of the array
 * Done by: Mekonen & Gebrekidan
 */
void counting_sort(int *array, size_t size)
{
	int max_value, j, *count_array, *aux;
	size_t i;

	/* Check if the array is valid for sorting */
	if (!array || size < 2)
		return;

	/* Find the maximum value in the array */
	max_value = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	/* Allocate memory for the counting array and initialize to zero */
	count_array = calloc((max_value + 1), sizeof(int));

	/* Count the occurrences of each element in the array */
	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	/* Update the counting array to store cumulative counts */
	for (j = 1; j <= max_value; j++)
		count_array[j] += count_array[j - 1];

	/* Print the counting array after updating */
	print_array(count_array, max_value + 1);

	/* Allocate memory for the auxiliary array */
	aux = malloc(sizeof(int) * size);

	/* Create the sorted array using the counting array */
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]--;
		aux[count_array[array[i]]] = array[i];
	}

	/* Copy the sorted array back to the original array */
	for (i = 0; i < size; i++)
		array[i] = aux[i];

	free(aux);
	free(count_array);
}

