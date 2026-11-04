#include <stdio.h>

/**
 * main - finds and prints the largest prime factor of 612852475143,
 * followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long n = 612852475143UL;
	unsigned long factor = 2;
	unsigned long largest = 0;

	while (factor * factor <= n)
	{
		if (n % factor == 0)
		{
			largest = factor;
			n /= factor;
		}
		else
		{
			factor++;
		}
	}
	if (n > 1)
		largest = n;
	printf("%lu\n", largest);
	return (0);
}
