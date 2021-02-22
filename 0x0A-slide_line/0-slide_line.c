#include "slide_line.h"

/**
* slide_line - slides and merges list of ints
* @line: pointer to array of ints
* @size: number of elements in array
* @direction: 1 or -1 to tell slide left or right respectively
* Return: 1 on success, 0 on failure
*/
int slide_line(int *line, size_t size, int direction)
{
	int Size, i = 0, j, cur_val = -1;

	Size = (int) size;
	if (!line)
		return (0);
	if (direction != -1 && direction != 1)
		return (0);
	j = direction;
	i = size / 2 + -1 * size / 2 * direction;
	// 0 if direction == 1 else size
	printf("i starts at %i\n", i);
	for (; i <= Size && cur_val < Size && i >= 0;)
	{
		if (cur_val == -1)
		{
			cur_val = i;
			i += j;
		}
		printf("%i %i\n", cur_val, i);
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
			// cur_val += j;
			i += j;
		}
		else if (line[cur_val] ==0 && line[i] == 0)
			i += j;
		else if (line[i] != line[cur_val] && line[i] != 0)
		{
			cur_val += j;
		}
		else
			i += j;
	}
	return (1);
}
