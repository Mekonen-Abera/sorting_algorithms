#include "sort.h"

/**
 * swap_nodes_left_to_right - Swaps nodes from left to right in a doubly linked list.
 * @list: Pointer to the list.
 * @head: Pointer to the head node.
 * @aux: Auxiliary pointer.
 * Return: Nothing
 */
void swap_nodes_left_to_right(listint_t **list, listint_t *head, listint_t *aux)
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
 * swap_nodes_right_to_left - Swaps nodes from right to left in a doubly linked list.
 * @list: Pointer to the list.
 * @head: Pointer to the head node.
 * @aux: Auxiliary pointer.
 * Return: Nothing
 */
void swap_nodes_right_to_left(listint_t **list, listint_t *head, listint_t *aux)
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
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 * @list: Pointer to the list head
 * Return: Nothing
 **/
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

			while (head->next)
			{
				if (head->n > head->next->n)
				{
					aux = head->next;
					swap_nodes_left_to_right(list, head, aux);
					flag = 1;
				}
				else
					head = head->next;
			}

			if (flag == 0)
				break;

			flag = 0;

			while (head->prev)
			{
				if (head->prev->n > head->n)
				{
					swap_nodes_right_to_left(list, head, aux);
					flag = 1;
				}
				else
					head = head->prev;
			}
		}
	}
}

