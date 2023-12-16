#include "sort.h"

/**
 * swap_int - Swaps the values of two integers.
 * @a: Pointer to integer a.
 * @b: Pointer to integer b.
 * Description: Done by Mekonen Abera & Gebrekidan Alemayehu
 */
void swap_int(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 * Bubble Sort algorithm.
 * @array: Pointer to an array of integers.
 * @size: The number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
    int swapped = 1;  /* Flag to track if any swaps were made*/
    size_t i, length = size;

    while (swapped == 1)
    {
	    swapped = 0;  /* Reset the swap flag for each pass*/
	    for (i = 1; i < length; i++)
	    {
		    if (array[i - 1] > array[i])
		    {
			    swap_int(&array[i - 1], &array[i]);
			    swapped = 1;
			    print_array(array, size);
		    }
	    }
	    length--;  /* Reduce the length of the array for each pass*/
    }
}

