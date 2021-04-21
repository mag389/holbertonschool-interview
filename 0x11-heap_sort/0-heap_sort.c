#include "sort.h"

void heapify(int *array, size_t size, unsigned int idx, size_t print);
/**
* heap_sort - performs heap sort on array
* Return: void
* @array: the list of numbers to sort
* @size: the size of the array
*/
void heap_sort(int *array, size_t size)
{
/*	unsigned int i;*/
	int tmp, i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
* heapify - makes array into heap form
* Return: void
* @array: the list of numbers to sort
* @size: the size of the array
* @idx: current spot in the heap
* @print: how big is the orginal array for printing
*/
void heapify(int *array, size_t size, unsigned int idx, size_t print)
{
	unsigned int left, rdx, lg;
	int temp;

	lg = idx;
	left = 2 * idx + 1;
	rdx = 2 * idx + 2;
	if (left < size && array[left] > array[lg])
		lg = left;
	if (rdx < size && array[rdx] > array[lg] && array[rdx] > array[left])
		lg = rdx;
	if (lg != idx)
	{
		temp = array[idx];
		array[idx] = array[lg];
		array[lg] = temp;
		print_array(array, print);
		heapify(array, size, lg, print);
	}
}
