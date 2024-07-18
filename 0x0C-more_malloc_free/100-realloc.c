#include <stdlib.h>
#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @old_size: The size, in bytes, of the allocated space for ptr.
 * @new_size: The new size, in bytes of the new memory block.
 * Return: A pointer to the newly allocated memory block.
 * If new_size == old_size, return ptr.
 * If new_size == 0 and ptr is not NULL, return NULL.
 * If ptr is NULL, return a pointer to a newly allocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *new_ptr;
    unsigned int i;
    if (new_size == old_size)
        return (ptr);
    if (ptr == NULL)
    {
        new_ptr = malloc(new_size);
        if (new_ptr == NULL)
            return (NULL);
        return (new_ptr);
    }
    if (new_size == 0 && ptr != NULL)
    {
        free(ptr);
        return (NULL);
    }
    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return (NULL);
    for (i = 0; i < old_size && i < new_size; i++)
        ((char *)new_ptr)[i] = ((char *)ptr)[i];
    free(ptr);
    return (new_ptr);
}
