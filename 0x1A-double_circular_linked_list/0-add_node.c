#include "list.h"

/**
* add_node_end - adds new node at end
* Return: the new node or NULL
* @list: the head node of list to add to
* @str: the string for new node
*/
List *add_node_end(List **list, char *str)
{
	List *new;

	if (!str)
		return (NULL);
	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	new->next = new;
	new->prev = new;

	if (*list == NULL)
		*list = new;
	else
	{
		new->next = *list;
		new->prev = (*list)->prev;
		new->next->prev = new;
		new->prev->next = new;
	}
	return (new);
}

/**
* add_node_begin - adds new node at beginning
* Return: NULL or the new node
* @list: pointer to head of list to add to
* @str: the new string to add to list
*/
List *add_node_begin(List **list, char *str)
{
	List *new;

	if (!str)
		return (NULL);
	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	new->next = new;
	new->prev = new;

	if (*list)
	{
		new->next = *list;
		new->prev = (*list)->prev;
		(*list)->prev = new;
		new->prev->next = new;
	}
	*list = new;
	return (new);
}
