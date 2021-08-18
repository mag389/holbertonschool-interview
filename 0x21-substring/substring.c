#include "substring.h"

/**
* find_substring - finds substring of all words
* Return: an array of indices of where the substrings start, or NULL
* @s: string to scan
* @words: list of words all substrings must be a concatenation arrangement of
* @nb_words: number of elements in array words
* @n: holds address at which to store number of elements in returned array
* all words are smae length
*/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int len, s_len, nb_cpy = nb_words, *inds, i, j;
	int found = 0, used;

	if (s == NULL || words == NULL || nb_words == 0 || n == NULL)
		return (NULL);
	s_len = strlen(s);
	len = strlen(words[0]);
	inds = malloc(s_len * sizeof(int));
	if (inds == NULL)
		return (NULL);
	for (i = 0; i <= s_len - nb_words * len; i++)
	{
/*		printf("i: %i\n", i);*/
		found = 0, used = 0;
		for (j = 0; j < nb_words; j++)
		{
			if ((found & (1 << j)) == 0 &&
				!strncmp(&s[i + used * len], words[j], len))
			{
/*				printf("strings %s %s\n", &s[i + used * len], words[j]);*/
/*				printf("into if j:%i i:%i\n", j, i);*/
/*				printf("\t prior found: %i\n", found);*/
				found = found | 1 << j;
/*				printf("\t post  found: %i\n", found);*/
				j = -1;
				used++;
			}
		}
		if (found == (1 << nb_cpy) - 1)
		{
/*			printf("\t found: %i i: %i\n", found, i);*/
			inds[*n] = i;
			(*n)++;
		}
	}
	return (inds);
}
