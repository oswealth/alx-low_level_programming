#include <stdlib.h>
#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - function that creates an array of chars,
 *  and initializes it with a specific char
 * @s1: first bytes of the memory
 * @s2: first bytes of the memory
 * @n: first bytes of the memory
 * Return: pointer to the resulting string dests
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	unsigned int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		;

	ptr = malloc(sizeof(*ptr) * (i + n + 1));

	if (new_str == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		ptr[i] = s1[i];

	for (j = 0; s2[j] != '\0' && j < n; j++)
		ptr[i + j] = s2[j];

	ptr[i + j] = '\0';

	return (ptr);
}
