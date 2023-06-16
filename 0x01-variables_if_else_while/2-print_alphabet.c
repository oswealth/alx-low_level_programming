#include <stdio.h>
/**
 * main - Entry point
 * prints the alphabet in lowercase, followed by a new line
 * Return: Always 0
*/
int main(void)
{
	int n = 'a';

	while (n <= 'z')
	{
		putchar(n);
		n++;
	}
	putchar('\n');
	return (0);
}
