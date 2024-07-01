#include "main.h"
/**
 * rev_string - reverses a string
 * @s: pointer to the string to reverse
 */
void rev_string(char *s)
{
    int len = 0, i;
    char temp;
    // Find the length of the string
    while (s[len] != '\0')
    {
        len++;
    }
    // Swap characters from the start and end of the string
    for (i = 0; i < len / 2; i++)
    {
        temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}
