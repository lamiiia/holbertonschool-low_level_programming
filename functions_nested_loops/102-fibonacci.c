#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers, starting with 1 and 2,
 * separated by a comma and a space, followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long prev, current, next;
	int count;

	prev = 1;
	current = 2;
	printf("%lu, %lu", prev, current);
	for (count = 3; count <= 50; count++)
	{
		next = prev + current;
		printf(", %lu", next);
		prev = current;
		current = next;
	}
	printf("\n");
	return (0);
}
