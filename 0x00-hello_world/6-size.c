#include <stdio.h>

/**
 *main - prints the size of various types base on
 *the computer it is compiled and run..
 *Return: Always 0 (success)
 */

int main(void)
  
{
printf("size of a char: %zu byte(s)\n", sizeof(char));

printf("size of an int: %zu byte(s)\n", sizeof(int));
printf("size of long int: %zu byte(s)\n", sizeof(long int));
printf("size of long long int: %zu byte(s)\n", sizeof(long long int));
printf("size of float: %zu byte(s)\n",sizeof(float));
}
