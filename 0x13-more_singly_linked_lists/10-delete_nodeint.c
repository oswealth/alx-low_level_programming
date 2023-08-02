#include "lists.h"

/**
 * delete_nodeint_at_index -deletes the node at index of listint_t linked list
 * @head: pointer to the pointer to the head of list
 * @index: the index of the node that should be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int node;

	if (*head == NULL)
	return (-1);

	if (index == 0)
	{
	temp = *head;
	*head = (*head)->next;
	free(temp);
	return (1);
	}

	current = *head;
	for (node = 0; node < (index - 1); node++)
	{
	if (current->next == NULL)
	return (-1);
	current = current->next;
	}

	temp = current->next;
	current->next = temp->next;
	free(temp);

	return (1);
}
