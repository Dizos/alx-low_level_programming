#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h> /* For ssize_t */
#include <sys/uio.h>    /* For read, write */
#include <unistd.h>     /* For STDOUT_FILENO */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output.
 * @filename: name of the file to read.
 * @letters: number of letters to read and print.
 *
 * Return: actual number of letters it could read and print,
 * or 0 if the file can not be opened or read, filename is NULL,
 * or write fails or does not write the expected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters);

#ifdef __cplusplus
}
#endif

#endif /* MAIN_H */
