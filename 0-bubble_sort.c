#include <stdio.h>
#include "sort.h"

/**
 * swap_int - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 * Done by: Mekonen Abera
 */
void swap_int(int *a, int *b)
{
    int temp;
    
    temp = *a;
    
    *a = *b;
    *b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: Pointer to an array of integers
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
    int has_swapped = 1;
    size_t i, end = size;

    /* looping until no swaps are made in a pass */
    while (has_swapped == 1)
    {
	    has_swapped = 0;
	    for (i = 1; i < end; i++)
	    {
		    /* If the current element is greater than the next one, swap them */
		    if (array[i - 1] > array[i])
		    {
			    swap_int(&array[i - 1], &array[i]);
			    has_swapped = 1;
			    print_array(array, size);
		    }
	    }
	    end--;
    }
}
