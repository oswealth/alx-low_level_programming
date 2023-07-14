#include <stdlib.h>
#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - concatenate s1 and n bytes of s2; return ptr to string
 * @s1: string 1
 * @s2: string 2
 * @n: n bytes to concat from string 2
 *
 * Return: pointer to concatenated string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	unsigned int len1, len2, i, j;

	/* check for NULL arguments */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* get the lengths of the strings */
	len1 = strlen(s1);
	len2 = strlen(s2);

	/* allocate memory for the new string */
	ptr = malloc(sizeof(*ptr) * (len1 + n + 1));
	if (ptr == NULL)
		return (NULL);

	/* copy s1 to the new string */
	for (i = 0; i < len1; i++)
		ptr[i] = s1[i];

	/* copy the first n bytes of s2 to the new string */
	for (j = 0; j < n && j < len2; j++)
		ptr[i + j] = s2[j];

	/* add the null terminator */
	ptr[i + j] = '\0';

	return (ptr);
}
