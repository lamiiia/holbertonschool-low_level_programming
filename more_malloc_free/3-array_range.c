#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: the first value of the array
 * @max: the last value of the array
 *
 * Return: a pointer to the newly created array containing all the values
 * from min to max, or NULL if min is greater than max or if malloc fails
 */
int *array_range(int min, int max)
{
	int *array;
	int size;
	int i;

	if (min > max)
		return (NULL);
	size = max - min + 1;
	array = malloc(sizeof(int) * size);
	if (array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		array[i] = min + i;
	return (array);
}
