#include "palindrome.h"
/**
* is_palindrome - chekcs if int is palindrome
* @n: the int to check
* Return: 1 if palindrome ele 0
*/
int is_palindrome(unsigned long n)
{
	unsigned long cpy = n, rev = 0;

	while (cpy > 0)
	{
		rev *= 10;
		rev += cpy % 10;
		cpy /= 10;
	}
	return (n == rev);
}
