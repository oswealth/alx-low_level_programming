#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - Duplicate a string using malloc
 * @str: string to duplicate
 *
 * Return: Pointer to a the new duplicated string
 */

char *_strdup(char *str)
{
	char *d;
	int b, c;

	if (str == NULL)
		return (NULL);

	for (b = 0; str[b] != '\0'; b++)
		;

	d = malloc(b * sizeof(*d) + 1);
	if (d == NULL)
		return (NULL);

	for (c = 0; c < b; c++)
		b[c] = str[c];
	d[c] = '\0';

	return (a);
}
