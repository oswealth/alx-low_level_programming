#include <stdio.h>

 /**
  * main - Entry point
  *
  * Description: Print all possible combinations of two two-digit numbers.
  * Numbers should range from 0 to 99, digits 1 should be printed as 01.
  * `00 01` and `01 00` are considered as the same combination
  * You can only use `putchar` to print to console.
  * You can only use `putchar` up to 8 times.
  * Return: Always 0
  */

int main(void)
{
	int x, y;

	for (x = 0; x < 100; x++)
	{
	for (y = 0; y < 100; y++)
	{
	if (x < y)
	{
	putchar((x / 10) + 48);
	putchar((x % 10) + 48);
	putchar(' ');
	putchar((y / 10) + 48);
	putchar((y % 10) + 48);
	if (x != 98 || y != 99)
	{
	putchar(',');
	putchar(' ');
	}
	}
	}
	}
	putchar('\n');
	return (0);
}
