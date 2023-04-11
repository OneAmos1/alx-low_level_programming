#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
/**
 * read_textfile - A function that reads a text file and
 * prints the text to the posix standard output.
 * @filename: A pointer to a string containing
 * the name of the text file to read.
 * @letters: The number of bytes to read from the file.
 * Return: The number of bytes read, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fptr;
char *buffer;
ssize_t bytes_read, bytes_written;

if (filename == NULL)
return (0);

buffer = malloc(sizeof(char) * letters);

if (buffer == NULL)
return (0);
fptr = open(filename, O_RDONLY);

if (fptr == -1)
{
free(buffer);
return (0);
}

bytes_read = read(fptr, buffer, letters);


close(fptr);
if (bytes_read == -1)
{
free(buffer);
return (0);
}

bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
free(buffer);
if (bytes_written == -1 || bytes_written != bytes_read)
return (0);

free(buffer);

return (bytes_read);
}
