#include <unistd.h>

/**
 * main - writes a quote followed by a new line to the standard error
 *
 * Return: Always 1
 */
int main(void)
{
	char quote[] = "and that piece of art is useful\" - "
		"Dora Korpar, 2015-10-19\n";

	write(2, quote, sizeof(quote) - 1);
	return (1);
}
