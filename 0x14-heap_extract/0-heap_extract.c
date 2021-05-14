#include "binary_trees.h"

heap_t *get_last_node(heap_t *root);
/**
* heap_extract - extracts the top value from the heap
* Return: the value if extracted else 0
* @root: double pointer to root node
*/
int heap_extract(heap_t **root)
{
	/*int ret, sizeleft, sizeright, lf, rf, temp, size;*/
	int value, size;
	heap_t *last;

	if (!root || !(*root))
		return (0);
	/* printf("into the next extract %i\n", (*root)->n);*/
	size = binary_tree_size(*root);
	/* printf("into the next extract %i\n", (*root)->n);*/
	last = last_levelorder(*root, 0, size - 1);
	/* printf("does it fault in last\n");*/
	/*if (last == NULL) */
		/* printf("last is NULL\n"); */
	/*last = last_levelorder(*root, 0, size - 1);*/
	if (last == *root)
	{
		value = (*root)->n;
		free(*root);
		*root = NULL;
		return (value);
	}
	/* printf("right before value check\n");*/
	value = last->n;
	/* printf("exctracting new value %i\n", value);*/

	last->n = (*root)->n;
	(*root)->n = value;
	/* printf("later the root is %i\n", (*root)->n);*/
	if (last->parent && last->parent->left == last)
		last->parent->left = NULL;
	else if (last->parent && last->parent->right == last)
		last->parent->right = NULL;
	value = last->n;
	free(last);
	/* printf("before rebuild %i\n", (*root)->n);*/
	rebuild(*root);
	/* printf("after rebuild %i\n", (*root)->n);*/

	return (value);
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
* get_last_node - nonrecursive method
* @root: pointer to root of heap
* Return: heap_t of last node
*/
heap_t *get_last_node(heap_t *root)
{
	unsigned int n_nodes, mask = 1;

	n_nodes = binary_tree_size(root);
	while (n_nodes / mask > 1)
		mask = mask << 1;
	mask = mask >> 1;

	while (mask)
	{
		if (n_nodes & mask)
			root = root->right;
		else
			root = root->left;
		mask = mask >> 1;
	}

	return (root);
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
	/* printf("in last node %i\n", (root)->n);*/
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
	heap_t *swap_node = root;

	if (!root)
		return (NULL);
	if (!(root->left) && !(root->right))
		return (NULL);
	if (root->left && root->right)
	{
		if (root->left->n >= root->right->n)
		{
			if (root->left->n > root->n)
				swap_node = root->left;
		}
		else
		{
			if (root->right->n > root->n)
				swap_node = root->right;
		}
	}
	else if (root->left && !(root->right) && root->left->n > root->n)
		swap_node = root->left;
	else if (root->right && !(root->left) && root->right->n > root->n)
		swap_node = root->right;
	/* printf("in rebuild root=%i\n", root->n);*/
	if (swap_node != root)
	{
		temp = swap_node->n;
		swap_node->n = root->n;
		root->n = temp;
		rebuild(swap_node);
	}
	return (NULL);
}
