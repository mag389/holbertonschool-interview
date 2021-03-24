#include "binary_trees.h"

/**
* sorted_array_to_avl - makes an avl tree from sorted array
* Return: pointer to root node of avl tree
* @array: sorted array of ints to make into tree
* @size: how many ints are in size
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new_node;
	unsigned int middle;

	if (!array || size == 0)
		return (NULL);
	middle = size / 2 - (1 - size % 2);

	new_node = binary_tree_node(NULL, array[middle]);
	if (!new_node)
		return (NULL);

	new_node->left = sorted_array_to_avl(array, middle);
	if (new_node->left)
		new_node->left->parent = new_node;
	else if (middle > 0)
		return (NULL);
	new_node->right = sorted_array_to_avl(&array[middle + 1], size / 2);
	if (new_node->right)
		new_node->right->parent = new_node;
	else if (size / 2 > 0)
		return (NULL);

	return (new_node);
}
/**
* binary_tree_node - creates new node
* Return: the new node or NULL
* @parent: the parent node of the new node
* @value: the int value of the new node
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
