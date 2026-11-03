#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints all the numbers of base 16 in lowercase,
 * followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	char letter;

	n = 0;
	while (n < 10)
	{
		putchar(n + '0');
		n++;
	}
	letter = 'a';
	while (letter <= 'f')
	{
		putchar(letter);
		letter++;
	}
	putchar('\n');
	return (0);
}
