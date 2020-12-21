#include "binary_trees.h"
int completeness(const binary_tree_t *tree, int index, int nodes);
size_t binary_tree_size(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
/**
* heap_insert - inserts new node to heap
* Return: the new node or NULL
* @root: root node of the tree
* @value: the value of the new node
*/
heap_t *heap_insert(heap_t **root, int value)
{
	int temp, sizeleft, sizeright, compleft, fleft;
	heap_t *newh;

	if (!root)
		return (NULL);
	if (!(*root))
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	sizeleft = binary_tree_size((*root)->left);
	sizeright = binary_tree_size((*root)->right);
	compleft = completeness((*root)->left, 0, binary_tree_size((*root)->left));
	fleft = binary_tree_is_full((*root)->left);
/*
*	printf("sleft: %i - sright: %i - comp %i - full %i\n",
*	 sizeleft, sizeright, compleft, fleft);
*/
	if ((sizeleft == sizeright && compleft) || sizeleft == sizeright ||
		 (sizeleft != sizeright && !fleft))
	{
		newh = heap_insert(&((*root)->left), value);
		if (newh->parent == NULL)
		{
			(*root)->left = newh;
			newh->parent = (*root);
		}
		if (newh->parent->n < newh->n)
		{
			temp = newh->n;
			newh->n = newh->parent->n;
			newh->parent->n = temp;
			return (newh->parent);
		}
		else
			return (newh);
	}
	else
	{
		newh = heap_insert(&((*root)->right), value);
		if (newh->parent == NULL)
		{
			(*root)->right = newh;
			newh->parent = (*root);
		}
		if (newh->parent->n < newh->n)
		{
			temp = newh->n;
			newh->n = newh->parent->n;
			newh->parent->n = temp;
			return (newh->parent);
		}
		else
			return (newh);
	}
}
/**
* binary_tree_size - returns size of the binary tree
* Return: size_t size of the tree
* @tree: pointer to root node of the tree to be measured
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
/**
* completeness - tests completeness
* Return: 1 for complete else 0
* @tree: the root node of the tree
* @index: the index the node should be at
* @nodes: total number of nodes
*/
int completeness(const binary_tree_t *tree, int index, int nodes)
{
	if (!tree)
		return (1);
	if (index >= nodes)
		return (0);
	return (completeness(tree->left, 2 * index + 1, nodes) &&
		completeness(tree->right, 2 * index + 2, nodes));
}
/**
* binary_tree_is_full - checks if the binary tree is full
* Return: 1 for full else 0
* @tree: pointer to root node to check
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (binary_tree_size(tree->left) != binary_tree_size(tree->right))
		return (0);
	if (!(tree->right) && !(tree->left))
		return (1);
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	return (0);
}
