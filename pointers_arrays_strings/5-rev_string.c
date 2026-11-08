#include "main.h"

/**
 * rev_string - reverses a string
 * @s: the string to reverse
 */
void rev_string(char *s)
{
	int len;
	int i;
	int j;
	char tmp;

	len = 0;
	while (s[len] != '\0')
		len++;
	i = 0;
	j = len - 1;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}
