#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked listint_t list
 * @h: pointer to the head of the list
 * Return: the number of elements
 */

size_t listint_len(const listint_t *h)
{
	size_t num = 0;
	const listint_t *element = h;

	while (element != NULL)
	{
	element = element->next;
	num++;
	}
	return (num);
}
