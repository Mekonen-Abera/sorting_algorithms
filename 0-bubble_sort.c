#include "sort.h"

/**
 * swap_two_int - Swaping two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap_two_int(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, leng = size;
	bool bub = false;

	if (array == NULL || size < 2)
		return;

	while (bub == false)
	{
		bub = true;
		for (x = 0; x < leng - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				swap_two_int(array + x, array + x + 1);
				print_array(array, size);
				bub = false;
			}
		}
		leng--;
	}
}
