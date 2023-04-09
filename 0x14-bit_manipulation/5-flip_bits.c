#include <stdio.h>
#include "main.h"
/**
 *flip_bits - Writes a function that returns the number of
 *bits you need to flip to get from one number to another
 *@n: The actual number
 *@m: The new number to flip n to.
 *
 *Return: The number flip from n to m
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned int count = 0;
unsigned long int xor = n ^ m;
while (xor)
{
xor &= (xor - 1);
count++;
}
return (count);
}
