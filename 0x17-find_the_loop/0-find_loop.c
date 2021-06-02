#include "lists.h"
listint_t *rec_loop(listint_t *head, listint_t *tort, listint_t *hare);
/**
* find_listint_loop - finds loop in linked list
* Return: the loop node, or NULL
* @head: the head node
*/
listint_t *find_listint_loop(listint_t *head)
{
	if (head == NULL)
		return (NULL);
	if (head->next)
		return (rec_loop(head, head->next, head->next->next));
	return (NULL);
}

/**
* rec_loop - finds if ther is a loop with extra variable or two
* Return: the loop node or NULL
* @head: the head node
* @tort: tortoise node, advances slowly
* @hare: hare node, advances quickly
*/
listint_t *rec_loop(listint_t *head, listint_t *tort, listint_t *hare)
{
/*	printf("in tortoise/hare \n");*/
	if (hare == NULL)
		return (NULL);
	while (hare)
	{
/*		printf("tort: %d, hare: %d\n", tort->n, hare->n);*/
		if (hare == tort)
		{
			while (hare)
			{
				if (head == hare)
					return (head);
				hare = hare->next;
				head = head->next;
			}
		}
/*			return (locate_loop(head, tort, hare));*/
		if (!hare || !tort)
			return (NULL);
		tort = tort->next;
		hare = hare->next;
		if (hare->next)
			hare = hare->next;
		else
			return (NULL);
	}
	return (hare);
}
