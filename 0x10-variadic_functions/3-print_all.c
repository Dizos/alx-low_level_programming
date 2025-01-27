#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - Prints anything based on the format specified.
 * @format: A list of types of arguments passed to the function.
 *
 * Return: Nothing.
 */
void print_all(const char * const format, ...)
{
    va_list args;
    unsigned int i = 0, j = 0;
    char *str, *separator = "";
    const char t_args[] = "cifs";

    va_start(args, format);
    
    while (format && format[i])
    {
        while (t_args[j])
        {
            if (format[i] == t_args[j] && *separator)
            {
                printf("%s", separator);
                break;
            }
            j++;
        }
        j = 0;
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
                    str = "(nil)";
                printf("%s%s", separator, str);
                break;
            default:
                i++;
                continue;
        }
        separator = ", ";
        i++;
    }
    printf("\n");
    va_end(args);
}
