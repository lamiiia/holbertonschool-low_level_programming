#include <stdio.h>
#include <stdlib.h>

/**
 * is_number - checks that a string is made only of digits
 * @s: the string to check
 *
 * Return: 1 if s is a non-empty string of digits, 0 otherwise
 */
static int is_number(char *s)
{
	int i;

	if (s[0] == '\0')
		return (0);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * main - adds positive numbers
 * @argc: the number of arguments
 * @argv: the array of arguments
 *
 * Return: 0 on success, 1 if one of the arguments is not a number
 */
int main(int argc, char *argv[])
{
	int i;
	int sum;

	sum = 0;
	for (i = 1; i < argc; i++)
	{
		if (!is_number(argv[i]))
		{
			printf("Error\n");
			return (1);
		}
		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);
	return (0);
}
