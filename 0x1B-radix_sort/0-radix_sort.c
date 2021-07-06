#include "sort.h"
void radix_sort_r(int *array, size_t size, int step);
/**
* radix_sort - sorts array by radix algo
* Return: void
* @array: the array to sort
* @size: the size of the array
*/
void radix_sort(int *array, size_t size)
{
	if (!array || size < 1)
		return;
	radix_sort_r(array, size, 1);
}

/**
* radix_sort_r - radix sorts array recursive call
* Return: void
* @array: the array to sort
* @size: the size of the array
* @step: what level digit to use
*/
void radix_sort_r(int *array, size_t size, int step)
{
	int *work, i, j, workindex = 0, w = 0, digit = 0;

	(void)w;
/*	printf("size is: %i  step: %i\n", (int)size, step);*/
/*	print_array(array, size);*/
	work = malloc(size * sizeof(int));
	for (j = 0; j < 10; j++)
	{
/*
*		printf(" %i:%i A:%i step:%i i:\n",
*		digit, array[i] / step, array[i], step);
*/
		for (i = 0; i < (int)size; i++)
		{
			if (array[i] / step > 0)
				digit = 1;
/*			printf(" %i:%i , A:%i ", digit, array[i] / step, array[i]);*/
/*			printf("number: %i, reduced: %i == %i\n",*/
/*			array[i], array[i] / step % 10, j);*/
			if ((array[i] / step) % 10 == j)
			{
/*				printf("in the if %i\n", array[i]);*/
				work[workindex] = array[i];
/*				printf("work[worki]: %i\n", work[workindex]);*/
				workindex++;
			}
		}
/*		printf("ij = %i %i\n", i, j);*/
	}
/*	printf("workindex: %i\n", workindex);*/
	for (i = 0; i < (int)size; i++)
		if (array[i] != work[i])
			array[i] = work[i], w = 1;
/*	print_array(work, size);*/
	free(work);
/*	printf("w: %i d: %i \n", w, digit);*/
	if (digit != 0)
	{
		print_array(array, size);
		radix_sort_r(array, size, step * 10);
	}
}
