#include <stdio.h>
#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index
 * @n: A pointer to an unsigned long integer
 * @index: The index of the bit to set to 0, starting from 0
 *
 * Return: 1 for success, or -1 for error
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
if (index >= sizeof(unsigned long int) * 8)
return (-1);
*n &= ~(1UL << index);

return (1);
}
