#include <stdio.h>
#include "sort.h"

/**
 * swap_int - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer
 * Done by: Mekonen-Abera
 */
void swap_int(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * print_array - Prints the elements of an array.
 * @array: An integer pointer that points to an array of integers.
 * @size: The number of components in the array.
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");
}

/**
 * bubble_sort - Sorts an array of integers in increasing order
 *               using the Bubble Sort algorithm.
 * @array: Array of integers pointer.
 * @size: Number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
    int needs_swap = 1;
    size_t i, pass_length = size;

    while (needs_swap == 1)
    {
        needs_swap = 0;
        for (i = 1; i < pass_length; i++)
        {
            if (array[i - 1] > array[i])
            {
                swap_int(&array[i - 1], &array[i]);
                needs_swap = 1;
                print_array(array, size);
            }
        }
        pass_length--;
    }
}

