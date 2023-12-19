#include "sort.h"

/**
 * swap_left_to_right - Swaps nodes from left to right in a doubly linked list.
 * @list: Pointer to the list.
 * @head: Pointer to the head node.
 * @aux: Auxiliary pointer.
 */
void swap_left_to_right(listint_t **list, listint_t *head, listint_t *aux)
{
	if (head->prev)
		head->prev->next = aux;
	else
		*list = aux;
	if (aux->next)
		aux->next->prev = head;
	head->next = aux->next;
	aux->prev = head->prev;
	aux->next = head;
	head->prev = aux;
	print_list(*list);
}

/**
 * swap_right_to_left - Swaps nodes from right to left in a doubly linked list.
 * @list: Pointer to the list.
 * @head: Pointer to the head node.
 * @aux: Auxiliary pointer.
 */
void swap_right_to_left(listint_t **list, listint_t *head, listint_t *aux)
{
	aux = head->prev;
	aux->next->prev = aux->prev;
	if (aux->prev)
		aux->prev->next = aux->next;
	else
		*list = aux->next;
	aux->prev = aux->next;
	aux->next = aux->next->next;
	aux->prev->next = aux;
	if (aux->next)
		aux->next->prev = aux;
	print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using the Cocktail sort algorithm.
 * @list: Pointer to the list head.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *aux;
	int flag = 1;

	if (list)
	{
		head = *list;
		while (flag != 0)
		{
			flag = 0;

			/* Traverse the list from left to right */
			while (head->next)
			{
				if (head->n > head->next->n)
				{
					aux = head->next;
					swap_left_to_right(list, head, aux);
					flag = 1;
				}
				else
					head = head->next;
			}

			/* In case there were no swaps, break out of the iteration */
			if (flag == 0)
				break;

			flag = 0;

			/* Go through the list starting from its end and move towards its beginning */
			while (head->prev)
			{
				if (head->prev->n > head->n)
				{
					swap_right_to_left(list, head, aux);
					flag = 1;
				}
				else
					head = head->prev;
			}
		}
	}
}
