#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a file with specified content.
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
    int fd, len = 0, n_written;

    if (filename == NULL)
        return (-1);

    /* Open the file, create it if it doesn't exist, truncate it if it does */
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1)
        return (-1);

    /* If text_content is not NULL, write it to the file */
    if (text_content != NULL)
    {
        while (text_content[len])
            len++;

        n_written = write(fd, text_content, len);
        if (n_written == -1 || n_written != len)
        {
            close(fd);
            return (-1);
        }
    }

    /* Close the file */
    close(fd);

    return (1);
}
