#include "search.h"
#include <math.h>

/**
* linear_skip - does a jump search on a skiplist
* Return: pointer to first node where value is located
* @list: pointer to head of the list to search
* @value: value to search for
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	unsigned int a = 0, b = 0;/*, jump;*/
	skiplist_t *lista = list, *listb = list;

	if (!list)
		return (NULL);
	/*jump = sqrt(size);*/
	while (listb->n < value && listb->next)
	{
		a = b;
		lista = listb;
/* instead make it skip*/
		if (listb->express)
			listb = listb->express;
		b = listb->index;
		printf("Value checked at index [%i] = [%i]\n", (int) listb->index, listb->n);
		if (listb->express == NULL && listb->n < value)
		{
			a = b;
			lista = listb;
			while (listb->next)
				listb = listb->next;
			b = listb->index;
			break;
		}
	}
	printf("Value found between indexes [%u] and [%u]\n", a, b);
	while (lista->n < value)
	{
		printf("Value checked at index [%u] = [%i]\n", a, lista->n);
		a += 1;
		lista = lista->next;
		if (a == b + 1 || lista->next == NULL)
			break;
	}
	printf("Value checked at index [%u] = [%i]\n", a, lista->n);
	if (lista->n == value)
		return (lista);
	return (NULL);
}
