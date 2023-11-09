#include "lists.h"


/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the head of the list
 * @index: the index of the node, starting from 0
 * Return: the nth node, or NULL if it does not exist
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int n = 0;

	if (head == NULL)
		return (NULL);

	while (head->prev != NULL)
		head = head->prev;


	while (head != NULL)
	{
		if (n == index)
			break;
		head = head->next;
		n++;
	}

	return (head);
}
