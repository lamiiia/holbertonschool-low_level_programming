#include "dog.h"
#include <stdlib.h>

/**
 * copy_string - creates a copy of a string in newly allocated memory
 * @src: the string to copy
 *
 * Return: a pointer to the copy, or NULL if src is NULL or on failure
 */
static char *copy_string(char *src)
{
	char *copy;
	int len;
	int i;

	if (src == NULL)
		return (NULL);
	len = 0;
	while (src[len] != '\0')
		len++;
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		copy[i] = src[i];
	return (copy);
}

/**
 * new_dog - creates a new dog
 * @name: the name of the dog
 * @age: the age of the dog
 * @owner: the owner of the dog
 *
 * Return: a pointer to the new dog, or NULL if the function fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);
	dog->name = copy_string(name);
	if (dog->name == NULL && name != NULL)
	{
		free(dog);
		return (NULL);
	}
	dog->owner = copy_string(owner);
	if (dog->owner == NULL && owner != NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}
	dog->age = age;
	return (dog);
}
