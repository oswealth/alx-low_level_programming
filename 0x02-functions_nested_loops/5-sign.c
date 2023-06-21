#include "main.h"
 /**
  * print_sign - Print the sign of a number
  * @n: type integer, can be negative or positive
  *
  * Returns 1 and prints + if n is greater than zero
  * Returns 0 and prints 0 if n is zero
  * Returns -1 and prints - if n is less than zero
  */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		 _putchar('-');
		return (-1);
	}
	else
	{
		_putchar(48);
		return (0);
	}
}
