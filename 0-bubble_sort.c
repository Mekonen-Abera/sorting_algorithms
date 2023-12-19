#include <stdio.h>
#include "sort.h"

/**
 * swap_int - switches the values of two integers.
 * @a: The first integer a
 * @b: The second integer b
 * Done by: Mekonen & Gebrekidan
 */
void swap_int(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * bubble_sort - sorts an array of integers into ascending order
 * @array: pointer to an array of ints
 * @size: length of the array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
    int swapped = 1;
    size_t i, length = size;
    while (swapped == 1)
    {
	    swapped = 0;
	    for (i = 1; i < length; i++)
	    {
		    if (array[i - 1] > array[i])
		    {
			    swap_int(&array[i - 1], &array[i]);
			    swapped = 1;
			    print_array(array, size);
		    }
	    }
	    length--;
    }
}

