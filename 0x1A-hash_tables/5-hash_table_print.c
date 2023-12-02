#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht:   A pointer to the hash table
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmp;
	int flag;

	if (ht == NULL)
		return;

	printf("{");

	flag = 0;

	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		while (tmp != NULL)
		{
			if (flag == 1)
				printf(", ");

			printf("'%s': '%s'", tmp->key, tmp->value);

			flag = 1;

			tmp = tmp->next;
		}
	}

	printf("}\n");
}
