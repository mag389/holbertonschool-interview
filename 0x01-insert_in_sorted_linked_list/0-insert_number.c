#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * insert_node - inters new node sorted into list
 * @head: pointer to list to add to
 * @number: the value of the new node
 * Return: address of the new node or NULL
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else if ((*head)->n >= number)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		while (current->next != NULL && current->next->n <= number)
			current = current->next;
		new->next = current->next;
		current->next = new;
	}
	return (new);
}
