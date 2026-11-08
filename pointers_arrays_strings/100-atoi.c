#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the converted number, or 0 if there are no numbers
 */
int _atoi(char *s)
{
	int i;
	int sign;
	int num;
	int started;

	sign = 1;
	num = 0;
	started = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			num = (num * 10) - (s[i] - '0');
		}
		else if (started)
			break;
		else if (s[i] == '-')
			sign = -sign;
	}
	if (sign == 1)
		num = -num;
	return (num);
}
