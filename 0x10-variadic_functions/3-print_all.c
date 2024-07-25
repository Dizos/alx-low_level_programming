#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - Prints anything, followed by a new line.
 * @format: A list of types of arguments passed to the function.
 *
 * Return: Nothing.
 */
void print_all(const char * const format, ...)
{
    va_list args;
    unsigned int i = 0, j, printed = 0;
    char *str;
    const char t_args[] = "cifs";
    char *separator = "";

    va_start(args, format);
    
    while (format && format[i])
    {
        j = 0;
        while (t_args[j])
        {
            if (format[i] == t_args[j] && printed)
            {
                printf("%s", separator);
                break;
            }
            j++;
        }
        switch (format[i])
        {
            case 'c':
                printf("%s%c", separator, va_arg(args, int));
                break;
            case 'i':
                printf("%s%d", separator, va_arg(args, int));
                break;
            case 'f':
                printf("%s%f", separator, va_arg(args, double));
                break;
            case 's':
                str = va_arg(args, char *);
                if (!str)
