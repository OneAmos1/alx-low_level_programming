#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * check_args - checks the number of arguments
 * @argc: number of arguments
 *
 * Return: void
 */
void check_args(int argc)
{
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
}

/**
 * open_files - opens the source and destination files
 * @argv: array of arguments
 * @file_from: pointer to file descriptor for source file
 * @file_to: pointer to file descriptor for destination file
 *
 * Return: void
 */
void open_files(char *argv[], int *file_from, int *file_to)
{
mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

*file_from = open(argv[1], O_RDONLY);
if (*file_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

*file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
if (*file_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(*file_from);
exit(99);
}
}

/**
 * copy_file - copies the contents of one file to another
 * @file_from: file descriptor for source file
 * @file_to: file descriptor for destination file
 *
 * Return: void
 */
void copy_file(int file_from, int file_to)
{
ssize_t bytes_read, bytes_written;
char buffer[BUFFER_SIZE];

while ((bytes_read = read(file_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(file_to, buffer, bytes_read);
if (bytes_written != bytes_read)
{
dprintf(STDERR_FILENO, "Error: Can't write to %d\n", file_to);
close(file_from);
close(file_to);
exit(99);
}
}

if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %d\n", file_from);
close(file_from);
close(file_to);
exit(98);
}
}

/**
 * close_files - closes the source and destination files
 * @file_from: file descriptor for source file
 * @file_to: file descriptor for destination file
 *
 * Return: void
 */
void close_files(int file_from, int file_to)
{
if (close(file_from) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
close(file_to);
exit(100);
}

if (close(file_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
exit(100);
}
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, exit with error code on failure
 */
int main(int argc, char *argv[])
{
int file_from, file_to;

check_args(argc);

open_files(argv, &file_from, &file_to);

copy_file(file_from, file_to);

close_files(file_from, file_to);

return (0);
}
