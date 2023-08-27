#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 1024 /* initial buffer size */

/**
 * my_getline - function that reads a line from fd
 * @n: pointer to the size of the buffer
 * @lineptr: pointer to the buffer to store the line
 * @start: the start index of the unread data in the buffer
 * @end: the end index of the unread data in the buffer
 * Return: the number of characters read, or -1 on error or EOF
 */

ssize_t my_getline(char **lineptr, size_t *n, int fd)
{
	static char *buffer;
	static size_t size;
	static size_t start;
	static size_t end;

	if (lineptr == NULL || n == NULL || fd < 0)
	{
		 errno = EINVAL;
		return (-1);
	}
	if (buffer == NULL)
	{
		buffer = malloc(BUFFER_SIZE);
		if (buffer == NULL)
		{
			return (-1);
		}
		size = BUFFER_SIZE;
		start = end = 0;
	}
	if (*lineptr == NULL || *n == 0)
	{
		*lineptr = malloc(BUFFER_SIZE);
		if (*lineptr == NULL)
		{
			return (-1);
		}
		*n = BUFFER_SIZE;
	}

	ssize_t bytes_read = 0;
	ssize_t total_read = 0;
	char *newline = NULL;
	size_t len = 0;

	while (1)
	{
		if (start < end)
		{
			newline = memchr(buffer + start, '\n', end - start);
			if (newline != NULL)
			{
				len = newline - (buffer + start) + 1;
				break;
			}
		}
		if (end == size)
		{
			memmove(buffer, buffer + start, end - start);
			end -= start;
			start = 0;
			size *= 2;
			char *tmp = realloc(buffer, size);

			if (tmp == NULL)
			{
				return (-1);
			}
			buffer = tmp;
		}
		bytes_read = read(fd, buffer + end, size - end);
		if (bytes_read == -1)
		{
			return (-1);
		}
		if (bytes_read == 0)
		{
			if (start == end)
			{
				return (-1);
			}
			else
			{
				len = end - start;
				break;
			}
		}
		end += bytes_read;
		total_read += bytes_read;
	}
	if (*n < len)
	{
		char *tmp = realloc(*lineptr, len);

		if (tmp == NULL)
		{
			return (-1);
		}
		*lineptr = tmp;
		*n = len;
	}
	memcpy(*lineptr, buffer + start, len);
	start += len;
	return (total_read);
}
