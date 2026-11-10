#include "main.h"
#include <stddef.h>

/**
 * _strchr - locates a character in a string
 * @s: the string to search
 * @c: the character to locate
 *
 * Return: a pointer to the first occurrence of c in s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	while (1)
	{
		if (*s == c)
			return (s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}
