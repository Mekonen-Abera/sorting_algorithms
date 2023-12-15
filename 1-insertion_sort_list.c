#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion Sort algorithm.
 * @list: Double pointer to the double linked list.
 * Done by: Mekonen Abera
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *div1 = NULL, *aux = NULL, *tmp = NULL;

	/* Check if the list and *list are valid */
	if (!list || !*list)
		return;

	/* Check if there is more than one element in the list */
	if ((*list)->next)
	{
		div1 = *list;
		div1 = div1->next;

		/* Iterate through the list starting from the second element */
		while (div1)
		{
			/* Save the current node in auxiliary variable */
			aux = div1;
			div1 = div1->next;

			/* Move backward and swap nodes until in the correct order */
			while (aux->prev && aux->prev->n > aux->n)
			{
				/* Save the previous node */
				tmp = aux->prev;
				/* Adjust the pointers for the swap */
				aux->prev = tmp->prev;
				if (tmp->prev)
					tmp->prev->next = aux;
				tmp->next = aux->next;
				if (tmp->next)
					tmp->next->prev = tmp;
				tmp->prev = aux;
				aux->next = tmp;

				/* If the node is moved to the beginning, update the list */
				if (!aux->prev)
					*list = aux;

				/* Update the list for printing and continue swapping */
				tmp = *list;
				print_list(tmp);
			}
		}
	}
}

