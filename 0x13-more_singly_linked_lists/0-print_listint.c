#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: pointer to the head of the list
 *
 * Return: the number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t num = 0;
	const listint_t *element = h;

	while (element != NULL)
	{
	printf("%d\n", element->n);
	element = element->next;
	num++;
	}
	return (num);
}
