#include <stdio.h>
#include "main.h"
/**
 *get_endianness - Checks the endianness.
 *
 *Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
int i = 1;
char *m = (char *)&i;
if (*m == 1)
return (1);

else

return (0);
}
