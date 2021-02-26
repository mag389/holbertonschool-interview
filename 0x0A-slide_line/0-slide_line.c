#include "slide_line.h"
int reverse(int *arr, size_t size);
/**
* slide_line - slides and merges list of ints
* @line: pointer to array of ints
* @size: number of elements in array
* @direction: 1 or -1 to tell slide left or right respectively
* Return: 1 on success, 0 on failure
*/
int slide_line(int *line, size_t size, int direction)
{
	int Size, i = 0, j = 1, cur_val = -1;

	Size = (int) size;
	if (!line)
		return (0);
	if (direction != -1 && direction != 1)
		return (0);
	if (j == -1)
		reverse(line, size);
	/* printf("i starts at %i\n", i); */
	for (; i <= Size && cur_val < Size && i >= 0;)
	{
		if (cur_val == -1)
		{
			cur_val = i;
			i += j;
		}
		/* printf("%i %i\n", cur_val, i); */
		if (line[i] == line[cur_val] && line[cur_val] != 0)
		{
			line[cur_val] *= 2;
			line[i] = 0;
			cur_val += j;
			i += j;
		}
		else if (line[cur_val] == 0 && line[i] != 0)
		{
			line[cur_val] += line[i];
			line[i] = 0;
			/* cur_val += j; */
			i += j;
		}
		else if (line[cur_val] == 0 && line[i] == 0)
			i += j;
		else if (line[i] != line[cur_val] && line[i] != 0)
		{
			cur_val += j;
		}
		else
			i += j;
	}
	if (direction == -1)
		reverse(line, size);
	return (1);
}

/**
* reverse - reverses array
* @arr: the array
* @size: length of it
* Return: 1 or 0 failure
*/
int reverse(int *arr, size_t size)
{
	unsigned int i;
	int temp;

	for (i = 0; i < size / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - 1 - i] = temp;
	}
	return (1);
}
