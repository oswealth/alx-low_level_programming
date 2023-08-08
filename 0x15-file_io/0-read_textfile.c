#include "main.h"
#include <stdlib.h>
/**
 * read_textfile - reads text file print to the POSIX standard output
 * @letters: number of letters it to be read and print
 * @filename: name of the file to read
 *
 * Return: actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd; /* file descriptor */
	char *buffer; /* buffer to store the data */
	ssize_t b_read, b_write; /* number of bytes read and written */

	if (!filename)	/* check if the filename is valid */
		return (0);

	fd = open(filename, O_RDONLY); /* open the file for reading only */
	if (fd < 0)
		return (0);

	buffer = malloc(sizeof(char) * letters); /* memory allocation */
	if (buffer == NULL)
	{
		return (0);
	}

	b_read = read(fd, buffer, letters); /* read data from file into buf */
	if (b_read < 0)
	{
		free(buffer);
		return (0);
	}
	buffer[b_read] = '\0';
	close(fd);

	b_write = write(STDOUT_FILENO, buffer, b_read);
	free(buffer);
	if (b_write < 0)
		return (0);

	return (b_write);
}
