#include <stdlib.h>
#include "main.h"

/**
 * _calloc - Allocates memory for an array, using malloc.
 * @nmemb: The number of elements in the array.
 * @size: The size of each element.
 * Return: A pointer to the allocated memory.
 * If nmemb or size is 0, returns NULL.
 * If malloc fails, returns NULL.
 * The memory is set to zero.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    char *ptr;
    unsigned int i;
    if (nmemb == 0 || size == 0)
        return (NULL);
    ptr = malloc(nmemb * size);
    if (ptr == NULL)
        return (NULL);
    for (i = 0; i < (nmemb * size); i++)
        ptr[i] = 0;
    return (ptr);
}
