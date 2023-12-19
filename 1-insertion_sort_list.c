#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to be swaped.
 * @n2: The second node to be swapped.
 * Done by: Mekonen & Gebrekidan
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	/* Adjust next pointers for the first node */
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;

	/* Adjust prev pointers for the second node */
	n2->prev = (*n1)->prev;
	n2->next = *n1;

	/* Update next pointer for the previous node of the first node */
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		/* If the first node was the head, update the head */
		*h = n2;

	/* Update prev pointer for the first node */
	(*n1)->prev = n2;
	/* Update n1 to be the previous node of the second node */
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integersi
 * @list: A pointer to the head of a doubly-linked list of integers.
 * Done by: Mekonen & Gebrekidan
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	/* Check for a valid list with more than one element */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* Iterate through the list starting from the second element */
	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		/* Save the next node before potential swaps */
		tmp = iter->next;
		/* Start the insert pointer from the previous node */
		insert = iter->prev;

		/* Swap nodes until in the correct order */
		while (insert != NULL && iter->n < insert->n)
		{
			/* Swap nodes and print the list after each swap */
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}

