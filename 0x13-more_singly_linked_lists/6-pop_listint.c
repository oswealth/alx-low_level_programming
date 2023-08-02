#include "lists.h"

/**
 * pop_listint - deletes the head node of listint_t linked list
 * @head: double pointer to the head
 *
 * Return: the head node's data, or 0 if the list is empty
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int num;

	temp = *head;

	if (temp == NULL)
	return (0);

	*head = temp->next;
	num = temp->n;
	free(temp);
	return (num);
}
