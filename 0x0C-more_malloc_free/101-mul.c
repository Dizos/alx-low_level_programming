#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _is_digit - checks if a string contains only digits
 * @s: the string to be evaluated
 * Return: 1 if the string contains only digits, 0 otherwise
 */
int _is_digit(char *s)
{
    while (*s)
    {
        if (*s < '0' || *s > '9')
            return (0);
        s++;
    }
    return (1);
}
/**
 * _strlen - returns the length of a string
 * @s: the string to evaluate
 * Return: the length of the string
 */
int _strlen(char *s)
{
    int len = 0;
    while (*s++)
        len++;
    return (len);
}
/**
 * _multiply - multiplies two numbers represented as strings
 * @num1: the first number
 * @num2: the second number
 * Return: a pointer to the result string
 */
char *_multiply(char *num1, char *num2)
{
    int len1 = _strlen(num1);
    int len2 = _strlen(num2);
    int *result = calloc(len1 + len2, sizeof(int));
    char *final_result;
    int i, j, carry, n1, n2, sum;
    if (!result)
        return (NULL);
    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        n1 = num1[i] - '0';
        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            sum = n1 * n2 + result[i + j + 1] + carry;
            carry = sum / 10;
            result[i + j + 1] = sum % 10;
        }
        result[i + j + 1] += carry;
    }
    final_result = malloc(len1 + len2 + 1);
    if (!final_result)
    {
        free(result);
        return (NULL);
    }
    i = 0;
    j = 0;
    while (i < len1 + len2 && result[i] == 0)
        i++;
    while (i < len1 + len2)
        final_result[j++] = result[i++] + '0';
    final_result[j] = '\0';
    free(result);
    return (final_result[0] == '\0') ? strdup("0") : final_result;
}
/**
 * main - multiplies two positive numbers
 * @argc: the number of arguments
 * @argv: the array of arguments
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
    char *result;
    if (argc != 3 || !_is_digit(argv[1]) || !_is_digit(argv[2]))
    {
        printf("Error\n");
        return (98);
    }
    result = _multiply(argv[1], argv[2]);
    if (!result)
    {
        printf("Error\n");
        return (98);
    }
    printf("%s\n", result);
    free(result);
    return (0);
}
