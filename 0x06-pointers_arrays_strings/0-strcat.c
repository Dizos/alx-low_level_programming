#include "main.h"
/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string to which the source string will be appended.
 * @src: The source string to be appended to the destination string.
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    /* Find the end of the destination string */
    while (dest[i] != '\0')
    {
        i++;
    }
    /* Append the source string to the destination string */
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    /* Add the terminating null byte */
    dest[i] = '\0';
    return dest;
}
