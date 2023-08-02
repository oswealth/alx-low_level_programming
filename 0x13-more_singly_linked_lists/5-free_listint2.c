#include "lists.h"

/**
 * free_listint2 - frees listint_t list and sets the head to NULL
 *
 * @head: double pointer to the head list
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	*head = NULL;
}
