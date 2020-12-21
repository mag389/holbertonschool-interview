#include <stdlib.h>
#include "binary_trees.h"

/**
* binary_tree_node - ceates new binary tree node
* @parent: pointer of parent node of node to be created
* @value: value to put in the new node
* Return: pointer to new node or NULL
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
