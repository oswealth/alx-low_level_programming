#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: pointer to a string containing a binary number
 *
 * Return: unsigned int with decimal value of binsry number, or 0 if error
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int a = 0; /* initialize the result to 0 */

	/* check if b is NULL or empty */
	if (b == NULL)
		return (0);

	while (*b != '\0') /* loop through each char in b */
	{
		/* check if the char is 0 or 1, otherwise return 0 */
		if (*b != '0' && *b != '1')
			return (0);

		a <<= 1;

		if (*b == '1')
			a += 1;

		b++;
	}
	return (a);
}
