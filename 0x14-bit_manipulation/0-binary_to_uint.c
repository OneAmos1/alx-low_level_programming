#include <stdio.h>
#include "main.h"
/**
 *binary_to_unit - converts a binary number to an unsigned int.
 *@b:is pointing to a string of 0 and 1 chars.
 *
 *Return: If b is NULL or contains chars not 0 or 1 - 0.
 * otherwise - the converted number.
 */

unsigned int binary_to_uint(const char *b)
{
unsigned int num = 0;
if (b == NULL)
return (0);
while (*b)
{
if (*b != '0' && *b != '1')
return (0);
num = (num << 1) | (*b++ - '0');
}
return (num);
}
