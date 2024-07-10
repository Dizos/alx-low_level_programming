#include "main.h"

/**
 * is_prime_helper - Helper function to determine if a number is prime
 * @n: The number to check
 * @i: The current divisor to test
 * Return: 1 if n is a prime number, 0 otherwise
 */
int is_prime_helper(int n, int i)
{
    if (n <= 1)
        return 0;
    if (i == 1)
        return 1;
    if (n % i == 0)
        return 0;
    return is_prime_helper(n, i - 1);
}
/**
 * is_prime_number - Returns 1 if the input integer is a prime number, otherwise return 0
 * @n: The number to check
 * Return: 1 if n is a prime number, 0 otherwise
 */
int is_prime_number(int n)
{
    return is_prime_helper(n, n / 2);
}
