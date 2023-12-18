#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two values in ascending or descending order.
 * @arr: Array.
 * @item1: Index of the first item.
 * @item2: Index of the second item
 * Done by: Mekonen & Gebrekidan
 * @order: 1 for ascending order, 0 for descending order.
 */
void swap(int arr[], int item1, int item2, int order)
{
    int temp;

    /* Check the order condition before swapping */
    if (order == (arr[item1] > arr[item2]))
    {
	    temp = arr[item1];
	    arr[item1] = arr[item2];
	    arr[item2] = temp;
    }
}

/**
 * merge - Merges bitonic sequences recursively in both orders.
 * @arr: Array.
 * @low: Index of the first element.
 * @nelemnt: Number of elements.
 * @order: 1 for ascending order, 0 for descending order.
 */
void merge(int arr[], int low, int nelemnt, int order)
{
    int mid, i;

    if (nelemnt > 1)
    {
	    mid = nelemnt / 2;
	    /* Swap elements based on the given order */
	    for (i = low; i < low + mid; i++)
		    swap(arr, i, i + mid, order);
	    merge(arr, low, mid, order);
	    merge(arr, low + mid, mid, order);
    }
}

/**
 * bitonicsort - Sorts bitonic sequences recursively.
 * @arr: Array.
 * @low: Index of the first element.
 * @nelemnt: Number of elements.
 * @order: 1 for ascending order, 0 for descending order.
 * @size: Array length.
 */
void bitonicsort(int arr[], int low, int nelemnt, int order, int size)
{
    int mid;

    if (nelemnt > 1)
    {
	    /* Print merging information */
	    if (order >= 1)
		    printf("Merging [%i/%i] (UP):\n", nelemnt, size);
	    else
		    printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
	    /* Print the current sub-array */
	    print_array(&arr[low], nelemnt);
	    mid = nelemnt / 2;
	    /* Recursively sort and merge sub-arrays */
	    bitonicsort(arr, low, mid, 1, size);
	    bitonicsort(arr, low + mid, mid, 0, size);
	    merge(arr, low, nelemnt, order);
	    /* Print the result after merging */
	    if (order <= 0)
		    printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
	    if (order >= 1)
		    printf("Result [%i/%i] (UP):\n", nelemnt, size);
	    print_array(&arr[low], nelemnt);
    }
}
/**
 * bitonic_sort - Prepares the terrain for the bitonic sort algorithm.
 * @array: Array.
 * @size: Array length.
 */
void bitonic_sort(int *array, size_t size)
{
    int order = 1;

    /* Check for invalid input */
    if (array == NULL || size < 2)
	    return;

    /* Start the bitonic sort process */
    bitonicsort(array, 0, size, order, size);
}
