#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t n_read, n_written;
    char *buffer;

    if (filename == NULL)
        return (0);

    /* Open the file */
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    /* Allocate memory for the buffer */
    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL)
    {
        close(fd);
        return (0);
    }

    /* Read from the file */
    n_read = read(fd, buffer, letters);
    if (n_read == -1)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    /* Write to the standard output */
    n_written = write(STDOUT_FILENO, buffer, n_read);
    if (n_written == -1 || n_written != n_read)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    /* Clean up */
    free(buffer);
    close(fd);

    return (n_written);
}
