#include "main.h"
/**
 * print_triangle - prints a triangle of a specified size
 * @size: size of the triangle to print
 *
 * Description: If size is 0 or less, prints only a new line.
 * Uses only _putchar to print output.
 */
void print_triangle(int size)
{
    int row, column;
    if (size <= 0)
    {
        _putchar('\n');
        return;
    }
    for (row = 1; row <= size; row++)
    {
        for (column = 1; column <= size; column++)
        {
            if (column <= size - row)
                _putchar(' ');
            else
                _putchar('#');
        }
        _putchar('\n');
    }
}
