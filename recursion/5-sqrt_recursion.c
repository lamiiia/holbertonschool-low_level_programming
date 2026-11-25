#include "main.h"

/**
 * _sqrt_helper - looks for the natural square root of n, starting from i
 * @n: the number
 * @i: the candidate for the square root
 *
 * Return: the square root of n, or -1 if n has no natural square root
 */
int _sqrt_helper(int n, int i)
{
	if (i > n / i)
		return (-1);
	if (i * i == n)
		return (i);
	return (_sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number
 *
 * Return: the natural square root of n, or -1 if n has none
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (0);
	return (_sqrt_helper(n, 1));
}
