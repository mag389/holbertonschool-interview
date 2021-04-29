#include "search_algos.h"
void print_array(int *array, size_t size);
/**
* advanced_binary - performs binary search for value in array
* Return: first index where value is located, or -1
* @array: pointer to first element of the array to search in, ASC unique
* @size: total number of elements of the array
* @value: the value to search for within the array
*/
int advanced_binary(int *array, size_t size, int value)
{
	unsigned int mid;
	int temp;

	if (!array || size == 0)
		return (-1);
	/*	find midpoint of array */
	mid = size / 2 - 1 + size % 2;
	/* printf("mid is %u", mid);*/
	print_array(array, size);
	/* useful base check */
	if (size == 1)
	{
		if (array[0] == value)
			return (0);
		return (-1);
	}
	/*	check midpoint for value compare, for recursive calls */
	if (mid != 0 && array[mid] == value && array[mid - 1] != value)
		return (mid);
	else if (array[mid] > value)
		return (advanced_binary(array, mid + 1, value));
	else if (array[mid] < value)
	{
		temp = advanced_binary((array + mid + 1), mid + 1 - size % 2, value);
		if (temp < 0)
			return (temp);
		else
			return (mid  + 1 + temp);
	}
	else if (array[mid] == value)
	{
		if (mid == 0)
			return (mid);
		if (array[mid - 1] != value)
			return (mid);
		return (advanced_binary(array, mid + 1, value));
	}
	else
		return (-1);
}

/**
* print_array - prints the array
* Return: void
* @array: pointer to first element
* @size: how much to print
*/
void print_array(int *array, size_t size)
{
	unsigned int i;

	printf("Searching in array: %i", array[0]);
	for (i = 1; i < size; i++)
		printf(", %i", array[i]);
	printf("\n");
}
