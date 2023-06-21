#include "main.h"

/**
  * print_alphabet - Print alphabet in lowercase using only `_putchar`
  * Return: 0
  */

void print_alphabet(void)
{
	char c;

	for (c = 97; c <= 122; c++)
	{
		_putchar(c);
	}
	_putchar('\n');
}
