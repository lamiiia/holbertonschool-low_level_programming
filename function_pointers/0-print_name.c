#include "function_pointers.h"
#include <stddef.h>

/**
 * print_name - prints a name
 * @name: the name to print
 * @f: pointer to the function used to print the name
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
