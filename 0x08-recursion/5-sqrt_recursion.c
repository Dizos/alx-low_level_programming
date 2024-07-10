#include "main.h"

/**
 * _sqrt_recursion_helper - Helper function to find the natural square root
 * @n: The number to calculate the square root of
 * @i: The current number to test as the potential square root
 * Return: The natural square root of n, or -1 if n does not have a natural square root
 */
int _sqrt_recursion_helper(int n, int i)
{
    if (i * i > n)
    {
        return -1;
    }
    if (i * i == n)
    {
        return i;
    }
    return _sqrt_recursion_helper(n, i + 1);
}

/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number to calculate the square root of
 * Return: The natural square root of n, or -1 if n does not have a natural square root
 */
int _sqrt_recursion(int n)
{
    if (n < 0)
    {
        return -1;
    }
    return _sqrt_recursion_helper(n, 0);
}
