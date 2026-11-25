#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - reads a text file and prints it to the standard output
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: the actual number of letters it could read and print, or 0 if the
 * file can not be opened or read, if filename is NULL, or if write fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nread;
	ssize_t nwritten;
	char *buffer;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}
	nread = read(fd, buffer, letters);
	close(fd);
	if (nread == -1)
	{
		free(buffer);
		return (0);
	}
	nwritten = write(STDOUT_FILENO, buffer, nread);
	free(buffer);
	if (nwritten == -1 || nwritten != nread)
		return (0);
	return (nwritten);
}
