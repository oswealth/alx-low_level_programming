#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at given index.
 * @n: unsigned long int.
 * @index: index of bit.
 *
 * Return: 1 if if success, -1 if it fails.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	/* check if index is valid */
	if (index > sizeof(n) * 8)
		return (-1);
	/* set the bit to 0 using bitwise AND */
	*n &= ~(1 << index);
	return (1);
}
