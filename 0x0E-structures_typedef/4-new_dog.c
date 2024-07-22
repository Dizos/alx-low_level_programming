#include <stdlib.h>
#include "dog.h"

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: pointer to the duplicated string or NULL if failed
 */
char *_strdup(char *str)
{
    char *dup;
    int len = 0, i;
    if (str == NULL)
        return (NULL);
    while (str[len])
        len++;
    dup = malloc(sizeof(char) * (len + 1));
    if (dup == NULL)
        return (NULL);
    for (i = 0; i < len; i++)
        dup[i] = str[i];
    dup[len] = '\0';
    return (dup);
}
/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 * Return: pointer to the new dog (dog_t) or NULL if failed
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *dog;
    dog = malloc(sizeof(dog_t));
    if (dog == NULL)
        return (NULL);
    dog->name = _strdup(name);
    if (dog->name == NULL)
    {
        free(dog);
        return (NULL);
    }
    dog->owner = _strdup(owner);
    if (dog->owner == NULL)
    {
        free(dog->name);
        free(dog);
        return (NULL);
    }
    dog->age = age;
    return (dog);
}
