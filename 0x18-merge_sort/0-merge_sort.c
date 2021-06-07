#include "sort.h"
void mergearrays(int *array, size_t size, size_t mp, int *b);
void topdownmerge(int *array, size_t size, int *b, size_t bsize);
/**
* merge_sort - merge sorts array
* Return: void
* @array: the numbers to sort
* @size: the size of the array
*/
void merge_sort(int *array, size_t size)
{
	unsigned int i;
	int *b;

	b = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		b[i] = array[i];
	topdownmerge(b, size, array, size);
	free(b);
}

/**
* topdownmerge - the recursive function for merge sorting
* Return: void
* @array: the array unsorted
* @size: size of the array
* @b: the second work array
* @bsize: the size of b
*/
void topdownmerge(int *array, size_t size, int *b, size_t bsize)
{
	int midpoint = size / 2;

	(void)bsize;
	if (size <= 1)
		return;
/*
*	printf("array: ");
*	print_array(array, size);
*	print_array(array, midpoint);
*	print_array((array + midpoint), size - midpoint);
*/
	topdownmerge(b, midpoint, array, midpoint);
	topdownmerge((b + midpoint), size - midpoint, (array + midpoint), 0);

	printf("Merging...\n[left]: ");
	print_array(array, midpoint);
	printf("[right]: ");
	print_array((array + midpoint), size - midpoint);
	mergearrays(array, size, midpoint, b);
	printf("[Done]: ");
	print_array(b, size);
}

/**
* mergearrays - merge the two arrays
* Return: void
* @array: numbers to get from
* @size:total size of the array
* @mp:midpoint of the array to split the array into 2
* @b: work array
*/
void mergearrays(int *array, size_t size, size_t mp, int *b)
{
	unsigned int i, rindex = mp, k = 0;
/*
*	printf("mergearrays:-----\n");
*	print_array(array, size);
*	print_array(b, size);
*	printf("those are a then b\n");
*/
	for (i = 0; i < size; i++)
	{
		if (k < mp && (rindex >= size || array[k] <= array[rindex]))
			b[i] = array[k], k++;
		else
			b[i] = array[rindex], rindex++;
	}
/*
*	print_array(b, size);
*	printf("------\n");
*/
}
