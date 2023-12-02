#include "hash_tables.h"


shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);


/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created hash table,
 *              or NULL if something went wrong
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->size = size;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}



/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The hash table you want to add or update the key/value to
 * @key: The key. key can not be an empty string
 * @value: The value associated with the key. value must be duplicated.
 *
 * Return: 1 if it succeeded, 0 otherwise
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node;
	shash_node_t *tmp;
	shash_node_t *prev;

	if (ht == NULL || key == NULL || value == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			if (tmp->value == NULL)
				return (0);
			return (1);
		}
		tmp = tmp->next;
	}

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (0);
	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (0);
	}
	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (0);
	}

	node->next = ht->array[index];
	ht->array[index] = node;

	tmp = ht->shead;
	prev = NULL;
	while (tmp != NULL && strcmp(tmp->key, key) < 0)
	{
		prev = tmp;
		tmp = tmp->snext;
	}
	if (prev == NULL)
	{
		node->sprev = NULL;
		node->snext = ht->shead;
		if (ht->shead != NULL)
			ht->shead->sprev = node;
		ht->shead = node;
		if (ht->stail == NULL)
			ht->stail = node;
	}
	else if (tmp == NULL)
	{
		node->sprev = ht->stail;
		node->snext = NULL;
		if (ht->stail != NULL)
			ht->stail->snext = node;
		ht->stail = node;
		if (ht->shead == NULL)
			ht->shead = node;
	}
	else
	{
		node->sprev = prev;
		node->snext = tmp;
		prev->snext = node;
		tmp->sprev = node;
	}

	return (1);
}


/**
 * shash_table_get - Retrieves a value associated with
 *                    a key in the sorted hash table
 * @ht: The hash table you want to look into
 * @key: The key you are looking for
 *
 * Return: The value associated with the element,
 *          or NULL if key couldn’t be found
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	if (ht->array[index] == NULL)
		return (NULL);

	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}

	return (NULL);
}



/**
 * shash_table_print - Prints a sorted hash table
 * @ht: The hash table
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;
	int flag;

	if (ht == NULL)
		return;

	printf("{");

	flag = 0;

	tmp = ht->shead;

	while (tmp != NULL)
	{
		if (flag == 1)
			printf(", ");

		printf("'%s': '%s'", tmp->key, tmp->value);

		flag = 1;

		tmp = tmp->snext;
	}

	printf("}\n");
}



/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order
 * @ht: The hash table
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;
	int flag;

	if (ht == NULL)
		return;

	printf("{");

	flag = 0;

	tmp = ht->stail;

	while (tmp != NULL)
	{
		if (flag == 1)
			printf(", ");

		printf("'%s': '%s'", tmp->key, tmp->value);

		flag = 1;

		tmp = tmp->sprev;
	}

	printf("}\n");
}



/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The hash table
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *tmp;
	shash_node_t *next;

	if (ht == NULL)
		return;

	tmp = ht->shead;

	while (tmp != NULL)
	{
		next = tmp->snext;

		free(tmp->key);
		free(tmp->value);

		free(tmp);

		tmp = next;
	}

	free(ht->array);

	free(ht);
}
