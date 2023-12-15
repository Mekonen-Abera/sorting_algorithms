#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 * Done by: Mekonen & Gebrekidan
 */
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * partition - Execute the partition process as required in Quick Sort.
 * @array: The pointer to the array to be sorted.
 * @low: Index of the low element.
 * @high: Index of the high element.
 * @size: The size of the array to be sorted.
 * Return: Index of the partition.
 */
int partition(int *array, int low, int high, size_t size)
{
    int p = array[high];
    int i = low - 1, j;

    for (j = low; j < high; j++)
    {
	    if (array[j] <= p)
	    {
		    i++;
		    swap(&array[i], &array[j]);
		    if (i != j)
			    print_array(array, size);
	    }
    }
    swap(&array[i + 1], &array[high]);
    high = i;
    print_array(array, size);
    return (i + 1);
}

/**
 * quick_sort2 - Two additional files, quick_sort2 and sorts an array
 * @array: Array of items to be sorted.
 * @low: Index of the low element.
 * @high: Index of the high element.
 * @size: The size of the array to be sorted.
 */
void quick_sort2(int *array, int low, int high, size_t size)
{
    int p;

    if (low < high)
    {
	    p = partition(array, low, high, size);
	    quick_sort2(array, low, p - 1, size);
	    quick_sort2(array, p + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers into ascending order
 * @array: Array to be sorted.
 * @size: The size of an array that needs to be sorted.
 */
void quick_sort(int *array, size_t size)
{
    int high = size - 1;

    if (size > 1)
	    quick_sort2(array, 0, high, size);
}
