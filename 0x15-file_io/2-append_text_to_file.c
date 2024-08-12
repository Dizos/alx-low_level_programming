#include <fcntl.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include "main.h" 

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: name of the file.
 * @text_content: NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success and -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int fd;
    ssize_t bytes_written;

    if (!filename)
        return (-1);

    fd = open(filename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1)
        return (-1);

    if (text_content == NULL)
    {
        close(fd);
        return (1);
    }

    bytes_written = write(fd, text_content, strlen(text_content));
    if (bytes_written == -1)
    {
        close(fd);
        return (-1);
    }

    close(fd);
    return (1);
}
