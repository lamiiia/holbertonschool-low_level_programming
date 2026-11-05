#include <stdio.h>

#define BASE 1000000000000000000UL

/**
 * print_big - prints a number stored in two parts (high and low)
 * @hi: the high part (number of times BASE)
 * @lo: the low part (less than BASE)
 */
void print_big(unsigned long hi, unsigned long lo)
{
	if (hi > 0)
		printf("%lu%018lu", hi, lo);
	else
		printf("%lu", lo);
}

/**
 * main - finds and prints the first 98 Fibonacci numbers, starting with
 * 1 and 2, separated by a comma and a space, followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long prev_hi, prev_lo, cur_hi, cur_lo, next_hi, next_lo;
	int count;

	prev_hi = 0;
	prev_lo = 1;
	cur_hi = 0;
	cur_lo = 2;
	for (count = 1; count <= 98; count++)
	{
		print_big(prev_hi, prev_lo);
		if (count < 98)
			printf(", ");
		next_hi = prev_hi + cur_hi;
		next_lo = prev_lo + cur_lo;
		if (next_lo >= BASE)
		{
			next_lo -= BASE;
			next_hi++;
		}
		prev_hi = cur_hi;
		prev_lo = cur_lo;
		cur_hi = next_hi;
		cur_lo = next_lo;
	}
	printf("\n");
	return (0);
}
