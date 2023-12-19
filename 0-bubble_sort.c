#include <stdio.h>
#include "sort.h"


/**
 * swap_int - swaps the values of two integers
 * @a: The first integer a
 * @b: The second integer b
 * Done by: Mekonen & Gebrekidan
 * Return: Nothing
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: Pointer to an array of integers
 * @size: The number of elements in the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int swapped = 1;
	size_t i, len = size;

	while (swapped == 1)
	{
		swapped = 0;
		for (i = 1; i < len; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap_int(&array[i - 1], &array[i]);
				swapped = 1;
				print_array(array, size);
			}
		}
		len--;
	}

}

