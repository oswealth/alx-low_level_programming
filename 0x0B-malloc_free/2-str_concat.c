#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenate two strings using malloc
 * @s1: string 1
 * @s2: string 2
 *
 * Return: pointer to concat string
 */

char *str_concat(char *s1, char *s2)
{
	char *a;
	int i, l, c, b;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		;
	for (l = 0; s2[l] != '\0'; l++)
		;

	a = malloc((i * sizeof(*s1)) + (l * sizeof(*s2)) + 1);
	if (a == NULL)
		return (NULL);

	for (c = 0, b = 0; c < (i + l + 1); c++)
	{
		if (c < i)
			a[c] = s1[c];
		else
			a[c] = s2[b++];
	}

	return (a);
}
