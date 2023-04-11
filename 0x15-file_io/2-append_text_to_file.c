#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text to end of file
 * @filename: name of file
 * @text_content: NULL terminated string to add to end of file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fptr, len = 0;

	if (!filename)
		return (-1);

	fptr = open(filename, O_WRONLY | O_APPEND);
	if (fptr == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[len])
			len++;
	}

	if (write(fptr, text_content, len) == -1)
	{
		close(fptr);
		return (-1);
	}

	close(fptr);
	return (1);
}
