#include "binary_trees.h"

/**
* heap_extract - extracts the top value from the heap
* Return: the value if extracted else 0
* @root: double pointer to root node
*/
int heap_extract(heap_t **root)
{
	/*int ret, sizeleft, sizeright, lf, rf, temp, size;*/
	int temp, size;
	heap_t *last;

	if (!root || !(*root))
		return (0);
	size = binary_tree_size(*root);
	last = last_levelorder(*root, 0, size - 1);

	temp = last->n;
	last->n = (*root)->n;
	(*root)->n = temp;
	if (last->parent && last->parent->left == last)
		last->parent->left = NULL;
	if (last->parent && last->parent->right == last)
		last->parent->right = NULL;
	temp = last->n;
	free(last);
	rebuild(*root);
	return (temp);
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
* last_levelorder - return last node in level order
* Return: heap_t
* @root: the root to get the last level order of
* @index: the current index of root
* @size: the total size of the tree
*/
heap_t *last_levelorder(heap_t *root, int index, int size)
{
	heap_t *left, *right;

	if (!root)
		return (NULL);
	if (index > size)
		return (NULL);
	if (index == size)
		return (root);
	left = last_levelorder(root->left, 2 * index + 1, size);
	right = last_levelorder(root->right, 2 * index + 2, size);
	if (left)
		return (left);
	if (right)
		return (right);
	return (NULL);
}
/**
* rebuild - fixes the heap
* Return: the former head node
* @root: the root
*/
heap_t *rebuild(heap_t *root)
{
	int temp;

	if (!root)
		return (NULL);
	if (!(root->left) && !(root->right))
		return (NULL);
	if (root->left && !(root->right) && root->left->n > root->n)
	{
		temp = root->left->n;
		root->left->n = root->n;
		root->n = temp;
		rebuild(root->left);
	}
	else if (root->right && !(root->left))
	{
		if (root->right->n > root->n)
		{
			temp = root->right->n;
			root->right->n = root->n;
			root->n = temp;
			rebuild(root->right);
		}
	}
	else if (root->left->n > root->n && root->left->n > root->right->n)
	{
		temp = root->left->n;
		root->left->n = root->n;
		root->n = temp;
		rebuild(root->left);
	}
	else if (root->right->n > root->n && root->right->n > root->left->n)
	{
		temp = root->right->n;
		root->right->n = root->n;
		root->n = temp;
		rebuild(root->right);
	}
	return (NULL);
}
