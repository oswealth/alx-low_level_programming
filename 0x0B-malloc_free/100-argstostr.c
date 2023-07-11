#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * argstostr - concatenate all arguments of your program with newline
 * @ac: argument count
 * @av: double pointer to array of strings passed to main
 *
 * Return: Null if fail, else return pointer to new string
 */

char *argstostr(int ac, char **av)
{
	char *a, *retp;
	int j, y, total;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (j = 0, total = 0; j < ac; j++)
	{
		for (y = 0; *(*(av + j) + y) != '\0'; y++, total++)
			;
		total++;
	}
	total++;

	a = malloc(total * sizeof(char));
	if (a == NULL)
		return (NULL);

	retp = a;
	for (j = 0; j < ac; j++)
	{
		for (y = 0; av[j][y] != '\0'; y++)
		{
			*a = av[j][y];
			a++;
		}
		*a = '\n';
		a++;
	}

	return (retp);
}
