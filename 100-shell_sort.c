#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence.
 * @array: Pointer to array for sorting
 * @size: size of array to sort
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, cmp;
	int temp;

/*validations*/
	if (size == 0 || size == 1)
		return;
/*Finds the max gap*/
	while (gap < (size / 3))
		gap = gap * 3 + 1;

/*comparing values from begining and from gap*/
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			cmp = i;
			while (cmp >= gap && array[cmp - gap] > temp)
			{
				array[cmp] = array[cmp - gap];
				cmp -= gap;
				array[cmp] = temp;
			}
		}
		print_array(array, size);
/*Gap decreases according to Knuth sequence*/
		gap /= 3;
	}
}
