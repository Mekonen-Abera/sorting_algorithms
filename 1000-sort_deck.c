#include "deck.h"

/**
 * aux_num_from_card - Converts card value to an integer.
 * @card_node: Pointer to the card node.
 * Done by: Mekonen & Gebrekidan
 * Return: Integer representation of the card value.
 **/
int aux_num_from_card(deck_node_t *card_node)
{
    int card_value, j;
    int values[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    char value_symbols[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '1', 'J', 'Q', 'K'};

    /* Map card value to its corresponding integer */
    for (j = 0; j < 13; j++)
    {
	    if (card_node->card->value[0] == value_symbols[j])
			    card_value = values[j];
    }
    return (card_value);
}

/**
 * num_sort - Sorts a doubly linked list of integers in 4 stages.
 * @list: Pointer to the list head.
 *
 * Return: Nothing
 **/
void num_sort(deck_node_t **list)
{
    deck_node_t *current_node, *temp_node1, *temp_node2, *aux1, *aux2;
    int flag = 0, i, aux_value1, aux_value2;
    unsigned int kind_value;

    current_node = *list;
    temp_node1 = *list;
    current_node = temp_node1;

    for (i = 0; i < 4; i++)
    {
	    kind_value = current_node->card->kind;
	    while (current_node->next && current_node->next->card->kind == kind_value)
	    {
		    aux_value1 = aux_num_from_card(current_node);
		    aux_value2 = aux_num_from_card(current_node->next);
		    flag = 0;
		    temp_node2 = current_node;
		    while (temp_node2 && temp_node2->card->kind == kind_value && aux_value1 > aux_value2)
		    {
			    aux1 = temp_node2;
			    aux2 = temp_node2->next;
			    /* Swap nodes if needed */
			    aux1->next = aux2->next;
			    if (aux2->next)
				    aux2->next->prev = aux1;
			    aux2->prev = aux1->prev;
			    aux2->next = aux1;
			    aux1->prev = aux2;
			    if (aux2->prev)
				    aux2->prev->next = aux2;
			    temp_node2 = aux2->prev;
			    if (!aux2->prev)
				    *list = aux2;
			    flag = 1;
			    if (!temp_node2)
				    break;
			    aux_value1 = aux_num_from_card(temp_node2);
			    aux_value2 = aux_num_from_card(temp_node2->next);
		    }
		    if (flag == 0)
			    current_node = current_node->next;
	    }
	    current_node = current_node->next;
    }
}

/**
 * kind_sort - Insertion sort a doubly linked list of integers
 * @list: Pointer to the list head
 *
 * Return: Nothing
 **/
void kind_sort(deck_node_t **list)
{
    deck_node_t *current_node, *temp_node1, *temp_node2, *aux1, *aux2;
    int flag;

    if (list)
    {
	    current_node = *list;
	    temp_node1 = *list;
	    current_node = temp_node1;
	    while (current_node->next)
	    {
		    if (current_node->next)
		    {
			    flag = 0;
			    temp_node2 = current_node;
			    while (temp_node2 && temp_node2->card->kind > temp_node2->next->card->kind)
			    {
				    aux1 = temp_node2;
				    aux2 = temp_node2->next;
				    /* Swap nodes if needed */
				    aux1->next = aux2->next;
				    if (aux2->next)
					    aux2->next->prev = aux1;
				    if (aux2)
				    {
					    aux2->prev = aux1->prev;
					    aux2->next = aux1;
				    }
				    if (aux1)
					    aux1->prev = aux2;
				    if (aux2->prev)
					    aux2->prev->next = aux2;
				    temp_node2 = aux2->prev;
				    if (!aux2->prev)
					    *list = aux2;
				    flag = 1;
			    }
		    }
		    if (flag == 0)
			    current_node = current_node->next;
	    }
    }
}

/**
 * sort_deck - Sorts a deck of cards.
 * @deck: Pointer to the deck.
 *
 * Return: Nothing
 **/
void sort_deck(deck_node_t **deck)
{
	if (deck)
	{
		kind_sort(deck);
		num_sort(deck);
	}
}

