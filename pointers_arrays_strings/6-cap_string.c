#include "main.h"

/**
 * is_separator - checks if a character separates words
 * @c: the character to check
 *
 * Return: 1 if c is a separator, 0 otherwise
 */
static int is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == ',' || c == ';')
		return (1);
	if (c == '.' || c == '!' || c == '?' || c == '"' || c == '(')
		return (1);
	if (c == ')' || c == '{' || c == '}')
		return (1);
	return (0);
}

/**
 * cap_string - capitalizes all words of a string
 * @str: the string to change
 *
 * Return: a pointer to str
 */
char *cap_string(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (i == 0 || is_separator(str[i - 1]))
				str[i] = str[i] - 'a' + 'A';
		}
	}
	return (str);
}
