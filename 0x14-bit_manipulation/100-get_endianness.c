#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	 /* create an unsigned int with value 1 */
	unsigned int n = 1;
	/* cast it to a char pointer and dereference it */
	char *endian = (char *)&n;

	/* if the first byte is 1, then it is little endian */
	if (*endian == 1)
		/* otherwise, it is big endian */
		return (1);

	return (0);
}
