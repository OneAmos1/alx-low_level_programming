#include <stdio.h>
#include "main.h"
/**
 *Print_binary - Prints the binary representation of a number
 *@n: The number to be printed in binary.
 *
 */
void print_binary(unsigned long int n)
{
if (n > 1)
print_binary(n >> 1);
_putchar((1 & n) + '0');
}
