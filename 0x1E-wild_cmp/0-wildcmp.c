#include <stdio.h>
#include "holberton.h"

/**
*wildcmp - compares two string with possible wildcards
*Return: 1 if identical else 0
*@s1: the fist string
*@s2: the second string
*/

int wildcmp(char *s1, char *s2)
{
	if (*s1 == 0 && *s2 == 0)
		return (1);
	if (*s1 == 0 && *s2 == '*')
		return (wildcmp(s1, &s2[1]));
	else if (*s1 == *s2)
		return (wildcmp(&s1[1], &s2[1]));
	else if (*s1 != '*' && *s2 != '*')
		return (0);
	else if (*s2 == '*')
	{
		if (*(s2 + 1) == 0)
			return (1);
		else if (*(s2 + 1) == '*')
			return (wildcmp(s1, &s2[1]));
		else if (*s1 == s2[1])
			return (wildcmp(&s1[1], s2) || wildcmp(&s1[0], &s2[1]));
		else
			return (wildcmp(&s1[1], s2));
	}
	return (7);
}
