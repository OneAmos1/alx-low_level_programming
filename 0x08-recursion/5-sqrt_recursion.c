#include "main.h"
int find_sqrt(int num, int root);
int _sqrt_recursion(int n);

/**
 *find _sqrt - Finds the natural  square root of inputted number.
 *@num: The number to find the square root of.
 *@root: The root to be tested.
 *
 *Return: if the number has a natural square root.
 *        if the number does not have a natural square root --1.
 *find _sqrt Finds natural square root of inputed number.
 */
int find_sqrt(int num, int root)
{
if ((root * root) == num)
return (root);
if (root == num / 2)
return (-1);
return (find_sqrt(num, root + 1));
}

/**
*_sqrt_recursion - Returns the natural square root of a number.
*find _sqrt Finds natural square root of inputed number.
*@n: The number to return the square root of.
*
*Return: If n has a natural square root - the natural square root of n.
*        If n does not have a natural square root --1.
*/
int _sqrt_recursion(int n)
{
int root = 0;
if (n < 0)
return (-1);
if (n == 1)
return (1);
return (find_sqrt(n, root));
}
