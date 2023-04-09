#include <unistd.h>
/**
 *_putchar -Writes the charater c to stdout
 * @c: The charater to be printed
 *
 * Return:Success on 1.
 * return -1 on error, and errorn is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
