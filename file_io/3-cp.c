#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

/**
 * close_fd - closes a file descriptor, exits with code 100 on failure
 * @fd: the file descriptor to close
 */
static void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_content - copies the content of a file descriptor into another
 * @fd_from: the file descriptor to read from
 * @fd_to: the file descriptor to write to
 * @file_from: the name of the source file
 * @file_to: the name of the destination file
 */
static void copy_content(int fd_from, int fd_to, char *file_from,
						 char *file_to)
{
	char buffer[BUF_SIZE];
	ssize_t nread;
	ssize_t nwritten;

	nread = read(fd_from, buffer, BUF_SIZE);
	while (nread != 0)
	{
		if (nread == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
					file_from);
			exit(98);
		}
		nwritten = write(fd_to, buffer, nread);
		if (nwritten != nread)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
		nread = read(fd_from, buffer, BUF_SIZE);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: the number of arguments
 * @argv: the array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int fd_from;
	int fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
				 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	copy_content(fd_from, fd_to, argv[1], argv[2]);
	close_fd(fd_from);
	close_fd(fd_to);
	return (0);
}
