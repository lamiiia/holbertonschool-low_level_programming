#include <unistd.h>

/**
 * main - writes a quote followed by a new line to the standard error
 *
 * Return: Always 1
 */
int main(void)
{
	write(2, "and that piece of art is useful\" - ", 35);
	write(2, "Dora Korpar, 2015-10-19\n", 24);
	return (1);
}
