#include "hash_tables.h"

/**
 * key_index - Gives the index of a key
 * @key: The key
 * @size: The size of the array of the hash table
 *
 * Return: The index at which the key/value pair should
 *             be stored in the array of the hash table
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;
	unsigned long int index;

	/* Use the hash_djb2 function to calculate the hash value of the key */
	hash = hash_djb2(key);

	index = hash % size;

	return (index);
}
