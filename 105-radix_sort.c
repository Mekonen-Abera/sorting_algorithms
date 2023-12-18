#include "sort.h"

/**
 * get_max_value - Returns the largest value from an array
 * @array: Pointer to the array
 * @size: Size of the array
 * Done by: Mekonen & Gebrekidan
 * Return: The maximum value of the array
 */
int get_max_value(int *array, size_t size)
{
	int max_value = array[0];
	size_t i = 0;

	while (i < size)
	{
		if (array[i] > max_value)
			max_value = array[i];
		i++;
	}
	return (max_value);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int *new_array;
	int i, max_value, exponent = 1;
	int array_size = size;

	if (size < 2 || !array)
		return;

	max_value = get_max_value(array, size);

	new_array = malloc(sizeof(int) * size);
	while (max_value / exponent > 0)
	{
		int counts[10] = {0};

		i = 0;

		while (i < array_size)
		{
			counts[(array[i] / exponent) % 10]++;
			i++;
		}

		if (counts != NULL)
		{
			for (i = 1; i < 10; i++)
				counts[i] += counts[i - 1];

			for (i = array_size - 1; i >= 0; i--)
			{
				new_array[counts[(int) array[i] / exponent % 10] - 1] = array[i];
				counts[(array[i] / exponent) % 10]--;
			}

			for (i = 0; i < array_size; i++)
				array[i] = new_array[i];
		}
		exponent *= 10;
		print_array(array, size);
	}
	free(new_array);
}

