#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints the alphabet in lowercase except q and e,
 * followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	letter = 'a';
	while (letter <= 'z')
	{
		if (letter != 'q' && letter != 'e')
			putchar(letter);
		letter++;
	}
	putchar('\n');
	return (0);
}
