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
	int *ptr;
	int j, range;

	/* check for invalid arguments */
	if (min > max)
		return (NULL);

	/* calculate the length of the array */
	range = max -  min + 1;

	/* allocate memory for the array */
	ptr = malloc(sizeof(int) * range);
	if (ptr == NULL)
		return (NULL);

	/* fill the array with values from min to max */
	for (j = 0; min <= max; j++)
		ptr[j] = min++;

	return (ptr);
}
