#include "deck.h"
#include <stdio.h>

/**
 * _strcmp - Compares two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: 1 if str1 and str2 are identical, or 0 otherwise.
 */
int _strcmp(const char *str1, const char *str2)
{
	size_t i = 0;
	if (str1 == NULL)
		return (0);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] == '\0' && str2[i])
		return (0);
	return (1);
}

/**
 * get_card_position - Returns the position according to card value.
 * @node: Represents the card node.
 *
 * Return: The card position.
 */
int get_card_position(deck_node_t *node)
{
    int card_value;

    card_value = node->card->value[0] - '0';

    if (card_value < 2 || card_value > 9)
    {
	    if (_strcmp(node->card->value, "Ace") == 1)
		    card_value = 1;
	    else if (_strcmp(node->card->value, "10") == 1)
		    card_value = 10;
	    else if (_strcmp(node->card->value, "Jack") == 1)
		    card_value = 11;
	    else if (_strcmp(node->card->value, "Queen") == 1)
		    card_value = 12;
	    else if (_strcmp(node->card->value, "King") == 1)
		    card_value = 13;
    }
    card_value += node->card->kind * 13;
    return (card_value);
}

/**
 * swap_card - Swaps the card with its previous one.
 * @card: The card to swap.
 * @deck: The card deck.
 *
 * Return: A pointer to the card inserted.
 */
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck)
{
    deck_node_t *previous = card->prev, *current = card;

    previous->next = current->next;
    if (current->next)
    {
	    current->next->prev = previous;
	    current->next = previous;
	    current->prev = previous->prev;
	    previous->prev = current;
	    if (current->prev)
		    current->prev->next = current;
	    else
		    *deck = current;
    }
    return (current);
}

/**
 * insertion_sort_deck - Sorts a doubly linked deck in ascending order
 * using the Insertion sort algorithm.
 * @deck: Double linked deck to sort.
 */
void insertion_sort_deck(deck_node_t **deck)
{
    int prev_value, current_value;
    deck_node_t *node;

    if (deck == NULL || (*deck)->next == NULL)
	    return;
    node = (*deck)->next;
    while (node)
    {
	    if (node->prev)
	    {
		    prev_value = get_card_position(node->prev);
		    current_value = get_card_position(node);
	    }
	    while (node->prev && prev_value > current_value)
	    {
		    prev_value = get_card_position(node->prev);
		    current_value = get_card_position(node);
		    node = swap_card(node, deck);
	    }
	    node = node->next;
    }
}

/**
 * sort_deck - Insertion sorts a deck.
 * @deck: The deck to sort.
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck);
}

