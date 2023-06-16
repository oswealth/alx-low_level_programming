#include <stdio.h>
/**
 * main - Entry point
 * prints all single digit numbers of base 10 starting from
 * Return: Always 0
 */
int main(void)
{
	int n;

	for (n = 0; n <= 9; n++)
	{
		printf("%d", n);
	}
	printf("\n");
	return (0);
}
