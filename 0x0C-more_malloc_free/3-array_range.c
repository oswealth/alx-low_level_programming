#include <stdlib.h>
#include "main.h"

/**
  *array_range - creates an array of integers.
  *@min: minimum value.
  *@max: maximum value.
  *
  *Return: pointer to newly created array.
  *NULL if malloc fails.
  *NULL if min > max.
  */

int *array_range(int min, int max)
{
	int *arr;
	int j, range;

	range = 0;

	/* check for invalid arguments */
	if (min > max)
		return (NULL);

	/* calculate the length of the array */
	range = ((max + 1) min - 1);

	/* allocate memory for the array */
	arr = malloc(range * sizeof(int));
	if (arr == NULL)
		return (NULL);

	/* fill the array with values from min to max */
	for (j = 0; j < len; j++)
	{
		arr[j] = min + j;
	}

	return (arr);
}
