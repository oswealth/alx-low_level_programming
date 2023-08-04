#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index.
 * @n: unsigned long int.
 *
 * @index: index of the bit.
 *
 * Return: value of the bit.
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int bit, check;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	bit = 1 << index;
	check = n & bit;
	if (check == bit)
		return (1);
	return (0);
}
