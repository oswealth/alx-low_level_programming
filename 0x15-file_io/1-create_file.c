#include "main.h"
#include <stdlib.h>

/**
 * create_file - creates a file and writes a text content to it
 *
 * @filename: name of file to be read
 * @text_content: NULL terminated string to be writen to file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd, nw, len = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (len = 0; text_content[len]; len++)
		;

	nw = write(fd, text_content, len);

	if (nw == -1)
		return (-1);

	close(fd);

	return (1);
}
