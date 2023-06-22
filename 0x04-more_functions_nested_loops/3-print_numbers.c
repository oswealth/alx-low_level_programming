#include "main.h"


/**
 *  * print_numbers - print numbers, from 0-9
 *   followed by a new line
 *
 *   * return: void
 */

void print_numbers(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		_putchar(i);
	}

	_putchar('\n');
}
