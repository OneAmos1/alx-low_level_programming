#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
/**
 * read_textfile - A function that reads a text file and
 * prints the text to the posix standard output.
 * @filename: A pointer to a string containing the
 * name of the text file to read.
 * @letters: The number of bytes to read from the file.
 * Return: The number of bytes read, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
FILE *fptr;
char *buffer;
ssize_t bytes_read;

if (filename == NULL)
return (0);

buffer = malloc(sizeof(char) * (letters + 1));
if (buffer == NULL)
return (0);

fptr = fopen(filename, "r");
if (fptr == NULL)
{
free(buffer);
return (0);
}

bytes_read = fread(buffer, sizeof(char), letters, fptr);

buffer[bytes_read] = '\0';

fclose(fptr);
printf("%s", buffer);

free(buffer);
return (bytes_read);
}
