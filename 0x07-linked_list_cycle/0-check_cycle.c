#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* check_cycle - checks for cycle in list
* @list: pointer to head of list to check
* Return: 0 if no cycle, else 1
*/
int check_cycle(listint_t *list)
{
	listint_t *tort, *hare;

        if (!list)
		return (0);
	tort = list;
	hare = list->next;
	while (hare)
	{
		if (tort == hare)
			return (1);
		tort = tort->next;
		hare = hare->next;
		if (hare)
			hare = hare->next;
		else
			return (0);
	}
	return (0);
}
