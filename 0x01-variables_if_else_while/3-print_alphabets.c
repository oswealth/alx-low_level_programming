#include <stdio.h>
/**
 * main - Entry point
 * program that print alphabet in lowercase, and then in uppercase
 * Return: Always 0
 */
int main(void)
{
	int n = 'a';
	int m = 'A';

	while (n <= 'z')
	{
		putchar(n);
		n++;
	}
	while (n <= 'Z')
	{
		putchar(m);
		n++;
	}
	putchar('\n');
	return (0);
}
