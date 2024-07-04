#include "main.h"
/**
 * _strncat - Concatenates two strings using at most n bytes from src.
 * @dest: The destination string to which the source string will be appended.
 * @src: The source string to be appended to the destination string.
 * @n: The maximum number of bytes to be used from src.
 * Return: A pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
    int i = 0;
    int j = 0;
    /* Find the end of the destination string */
    while (dest[i] != '\0')
    {
        i++;
    }
    /* Append the source string to the destination string, using at most n bytes */
    while (src[j] != '\0' && j < n)
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    /* Add the terminating null byte */
    dest[i] = '\0';
    return dest;
}
