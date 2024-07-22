#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - returns the length of a string
 * @str: string to measure
 *
 * Return: length of the string
 */
int _strlen(char *str)
{
    int len = 0;

    while (str[len])
        len++;

    return (len);
}

/**
 * _strcpy - copies a string
 * @dest: destination buffer
 * @src: source string
 *
 * Return: pointer to destination buffer
 */
char *_strcpy(char *dest, char *src)
{
    int i;

    for (i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';

    return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog (dog_t) or NULL if failed
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *dog;
    char *name_copy, *owner_copy;

    if (name == NULL || owner == NULL)
        return (NULL);

    dog = malloc(sizeof(dog_t));
    if (dog == NULL)
        return (NULL);

    name_copy = malloc((_strlen(name) + 1) * sizeof(char));
    if (name_copy == NULL)
    {
        free(dog);
        return (NULL);
    }
    _strcpy(name_copy, name);

    owner_copy = malloc((_strlen(owner) + 1) * sizeof(char));
    if (owner_copy == NULL)
    {
        free(name_copy);
        free(dog);
        return (NULL);
    }
    _strcpy(owner_copy, owner);

    dog->name = name_copy;
    dog->age = age;
    dog->owner = owner_copy;

    return (dog);
}
