#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * create_file - creates a file with rw------- permissions
 * @filename: name of file to create
 * @text_content: NULL terminated string to write to file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
int fptr, len = 0;

if (!filename)
return (-1);

fptr = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
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
