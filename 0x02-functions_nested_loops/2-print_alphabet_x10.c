#include "main.h"

 /**
  * print_alphabet_x10 - Print alphabet in lowercase 10 times
  *
  * Return: void
  */

void print_alphabet_x10(void)
{
	char c;
	int  i;

	for (i = 0; i <= 10; i++)
	{
		for (c = 97; c <= 122; c++)
		{
			_putchar(c);
		}
		_putchar('\n');
	}
}
