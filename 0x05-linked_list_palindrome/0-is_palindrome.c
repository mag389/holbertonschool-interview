#include <stdio.h>
#include <stdlib.h>
# include "lists.h"

/**
* is_palindrome - checks if singly linked list is palindrome
* @head: double pointer to head of list
* Return: 1 if palindrome else 0
*/
int is_palindrome(listint_t **head)
{
	if (!head)
		return (0);
	return (is_palindrome_r(head, head));
}

/**
* is_palindrome_r - checks palindrom with multiple args
* @head: head node
* @tail: tail node
* Return: 1 if palindrome else 0
*/
int is_palindrome_r(listint_t **head, listint_t **tail)
{
	int n;

	/* printf("comparing %is to %i ===\n", (*head)->n, (*tail)->n);*/
	if ((*tail)->next != NULL)
	{
		n = is_palindrome_r(head, &((*tail)->next));
		/* printf("result is %i \n", n);*/
		if (n == 0)
			return (0);
	}
	/* printf("comparing %is to %i ===\n", (*head)->n, (*tail)->n);*/
	if ((*head)->n == (*tail)->n)
	{
		*head = ((*head)->next);
		return (1);
	}
	return (0);
}
