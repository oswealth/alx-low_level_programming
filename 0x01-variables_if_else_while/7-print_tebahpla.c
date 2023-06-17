#include <stdio.h>
/**
 * main - Entry point
 * prints the lowercase alphabet in reverse
 * Return: Always 0
 */
int main(void)
{
	int n = 'z';


	while (n >= 'a')
	{
		putchar(n);
		n--;
	}
	putchar('\n');
	return (0);
}
