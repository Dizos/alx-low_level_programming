#include <unistd.h> 
#include <fcntl.h>  
#include <stdlib.h> 
#include "main.h"   

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output.
 * @filename: name of the file to read.
 * @letters: number of letters to read and print.
 *
 * Return: actual number of letters it could read and print,
 * or 0 if the file can not be opened or read, filename is NULL,
 * or write fails or does not write the expected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    ssize_t bytesRead, bytesWritten;
    char buffer[1024];
    int fd;

    if (!filename || !letters)
        return 0;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return 0;

    while (letters > 0)
    {
        bytesRead = read(fd, buffer, sizeof(buffer));
        if (bytesRead <= 0)
            break;

        bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
        if (bytesWritten != bytesRead || bytesWritten == -1)
        {
            close(fd);
            return 0;
        }

        letters -= bytesRead;
    }

    close(fd);
    return bytesRead + bytesWritten;
}
