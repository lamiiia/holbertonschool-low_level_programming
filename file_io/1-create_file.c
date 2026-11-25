#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - creates a file
 * @filename: the name of the file to create
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t nwritten;
	size_t len;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);
	len = 0;
	if (text_content != NULL)
	{
		while (text_content[len] != '\0')
			len++;
		nwritten = write(fd, text_content, len);
		if (nwritten == -1 || (size_t)nwritten != len)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
