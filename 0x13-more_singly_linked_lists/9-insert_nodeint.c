#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the pointer to the head of the list
 *
 * @idx: the index of the list where the new node should be added
 * @n: the data of the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *new_node, *temp = *head;
unsigned int x;

new_node = malloc(sizeof(listint_t));

if (new_node == NULL)
return (NULL);

new_node->n = n;

if (idx == 0)
{
new_node->next = temp;
*head = new_node;
return (new_node);
}

for (x = 0; x < (idx - 1); x++)
{
if (temp == NULL || temp->next == NULL)
return (NULL);

temp = temp->next;
}

new_node->next = temp->next;
temp->next = new_node;

return (new_node);
}
