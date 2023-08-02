#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of listint_t linked list
 * @head: pointer to the head of the list
 * @index: the index of the node, starting at 0
 *
 * Return: the nth node, or NULL if it does not exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL)
	{
	if (i == index)
	return (head);
	head = head->next;
	i++;
	}
	return (NULL);
}
