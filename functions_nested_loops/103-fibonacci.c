#include <stdio.h>

/**
 * main - finds and prints the sum of the even-valued terms of the
 * Fibonacci sequence (starting with 1 and 2) that do not exceed 4000000,
 * followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long prev, current, next, sum;

	prev = 1;
	current = 2;
	sum = 0;
	while (current <= 4000000)
	{
		if (current % 2 == 0)
			sum += current;
		next = prev + current;
		prev = current;
		current = next;
	}
	printf("%lu\n", sum);
	return (0);
}
