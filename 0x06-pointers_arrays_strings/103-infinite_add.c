#include "main.h"
/**
 * infinite_add - Adds two numbers represented as strings.
 * @n1: The first number.
 * @n2: The second number.
 * @r: The buffer to store the result.
 * @size_r: The size of the buffer.
 * Return: A pointer to the result, or 0 if the result cannot be stored in r.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int i, j, k, l, m, n;
    int carry = 0;
    int digit1, digit2, sum;
    for (i = 0; n1[i]; i++)
        ;
    for (j = 0; n2[j]; j++)
        ;
    if (i >= size_r || j >= size_r)
        return (0);
    r[size_r - 1] = '\0';
    i--, j--, k = size_r - 2;
    while (i >= 0 || j >= 0 || carry)
    {
        digit1 = (i >= 0) ? n1[i--] - '0' : 0;
        digit2 = (j >= 0) ? n2[j--] - '0' : 0;
        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        if (k < 0)
            return (0);
        r[k--] = (sum % 10) + '0';
    }
    if (k < 0)
        return (0);
    for (l = 0, m = k + 1; m < size_r - 1; l++, m++)
        r[l] = r[m];
    r[l] = '\0';
    return (r);
}
