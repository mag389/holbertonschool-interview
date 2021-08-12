#include <stdio.h>
#include <string.h>
#include "regex.h"
int singlecomp(char a, char b);
int starcomp(char const *str, char const *pattern);
int dotcomp(char const *str, char const *pattern);
/**
* regex_match - checks if a patter matches a string
* Return: 1 if match else 0
* @str: can be empty or any ascii char except . and *
* @pattern: can be empty of any ascii char
* . matches any single char
* * matchces zer or more preceding char
*/
int regex_match(char const *str, char const *pattern)
{
	int i = 0, j = 0;
	unsigned int ls, lp;

	if (strcmp(str, pattern) == 0)
		return (1);
	if (strchr(pattern, '.') == NULL && strchr(pattern, '*') == NULL)
		return (0);
	if (strchr(pattern, '*') == NULL)
	{
/*		printf("%s", strchr(pattern, '*'));*/
		return (dotcomp(str, pattern));
	}
	return (starcomp(str, pattern));
	(void) i;
	(void) j;
	ls = sizeof(str);
	(void) ls;
	lp = sizeof(pattern);
	return (lp);
}
/**
* starcomp - comparison with star wilds
* Return: 1 if same else 0
* @str: can be empty or any ascii char except . and *
* @pattern: can be empty of any ascii char
*/
int starcomp(char const *str, char const *pattern)
{
/*	printf("words -%s- -%s-\n", str, pattern);*/
	if (pattern[0] == '.' && pattern[1] == '*' && pattern[2] == 0)
		return (1);
	if (strcmp(str, pattern) == 0)
	{
/*		printf("in 1st");*/
		return (1);
	}
	if (*str == 0 && *pattern == 0)
	{
/*		printf("in 2 ");*/
		return (1);
	}
	if (singlecomp(*str, *pattern) && pattern[1] != '*')
	{
/*		printf("in 3 ");*/
		return (starcomp(&str[1], &pattern[1]));
	}
	if (!singlecomp(*str, *pattern) && pattern[1] != '*')
	{
/*		printf("in 4 ");*/
		return (0);
	}
	if (!singlecomp(*str, *pattern) && pattern[1] == '*')
	{
/*		printf("in 5 ");*/
		return (starcomp(str, &pattern[2]));
	}
	if (str[0] == 0 && pattern[0] == '.' && pattern[1] == '*')
		return (starcomp(str, &pattern[2]));
	if (str[0] == 0 || pattern[0] == 0)
	{
/*		printf("the extra check\n");*/
		return (0);
	}
	if (singlecomp(*str, *pattern) && pattern[1] == '*')
	{
/*		printf("in 6 ");*/
		return (starcomp(&str[1], pattern) ||
			starcomp(&str[0], &pattern[2]));
	}
	return (7);
}
/**
* singlecomp - compare single char with wild
* Return: 1 if match else 0
* @a: char a
* @b: char b
*/
int singlecomp(char a, char b)
{
	if (a == b)
		return (1);
	if (b == '.')
		return (1);
	return (0);
}
/**
* dotcomp - only comparison with single wildcards
* Return: 1 if same else 0
* @str: can be empty or any ascii char except . and *
* @pattern: can be empty of any ascii char
* . matches any single char
*/
int dotcomp(char const *str, char const *pattern)
{
	int i = 0;

	while (str[i] || pattern[i])
	{
		if (str[i] == pattern[i] || pattern[i] == '.')
			i++;
		else
			return (0);
	}
	return (1);
}
