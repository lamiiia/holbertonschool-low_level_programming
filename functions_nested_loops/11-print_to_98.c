#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - prints all integers from n to 98, followed by a new line
 * @n: the first number to print
 */
void print_to_98(int n)
{
	while (n != 98)
	{
		printf("%d, ", n);
		if (n < 98)
			n++;
		else
			n--;
	}
	printf("98\n");
}
