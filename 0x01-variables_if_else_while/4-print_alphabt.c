#include <stdio.h>
/**
 * main - Entry point
 * program that print alphabet in lowercase, except q and e
 * Return: Always 0
 */
int main(void)
{
	int n = 'a';

	while (n <= 'z')
	{
		if (n == 'e' || n == 'q')
		{
			n++;
			continue;
		}
		putchar(n);
		n++;
	}
	putchar('\n');
	return (0);
}

