#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of bytes of s2 to concatenate to s1.
 * Return: A pointer to the newly allocated space in memory containing s1,
 * followed by the first n bytes of s2, and null terminated.
 * If the function fails, it should return NULL.
 * If n is greater or equal to the length of s2 then use the entire string s2.
 * If NULL is passed, treat it as an empty string.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    char *concat;
    unsigned int i, j, len1, len2;
    if (s1 == NULL)
        s1 = "";
    if (s2 == NULL)
        s2 = "";
    for (len1 = 0; s1[len1] != '\0'; len1++)
        ;
    for (len2 = 0; s2[len2] != '\0'; len2++)
        ;
    if (n >= len2)
        n = len2;
    concat = malloc(len1 + n + 1);
    if (concat == NULL)
        return (NULL);
    for (i = 0; i < len1; i++)
        concat[i] = s1[i];
    for (j = 0; j < n; j++)
        concat[i + j] = s2[j];
    concat[i + j] = '\0';
    return (concat);
}
