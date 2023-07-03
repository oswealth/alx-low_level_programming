#include "main.h"

/**
 * _strstr - a function that locates a substring
 * @haystack: string
 * @needle: input
 *
 * Return: a pointer to the beginning of the located substring
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *l = haystack;
		char *j = needle;

		while (*l == *j && *j != '\0')
		{
			l++;
			j++;
		}

		if (*j == '\0')
			return (haystack);
	}

	return (0);
}
