#include <stdio.h>
#include <math.h>
/**
 * main - finds and prints the largest prime factor of the number 612852475143
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    long num = 612852475143;
    long largest_factor = 2;
    long i;
    // Divide out all factors of 2
    while (num % 2 == 0)
    {
        num /= 2;
    }
    // Check for odd factors from 3 upwards
    for (i = 3; i <= sqrt(num); i += 2)
    {
        while (num % i == 0)
        {
            largest_factor = i;
            num /= i;
        }
    }
    // If num is still greater than 2, then it is prime
    if (num > 2)
    {
        largest_factor = num;
    }
    printf("%ld\n", largest_factor);
    return (0);
}
