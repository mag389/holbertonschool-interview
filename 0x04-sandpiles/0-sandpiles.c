#include "sandpiles.h"
static void print_grid(int grid[3][3]);
/**
* sandpiles_sum - add two sandpiles
* @grid1: first pile, the one to stabilize
* @grid2: what to add to grid
* Return:void
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, stable;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	stable = check_stable(grid1);
	while (stable == 0)
	{
		printf("=\n");
		print_grid(grid1);
		topple_grid(grid1, grid2);
		stable = check_stable(grid1);
	}
}

/**
* topple_grid - breaks down the sandpile
* @grid1: the grid to topple
* @grid2: a second grid to hold values
* Return: nothing as of now
*/
int topple_grid(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid2[i][j] = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] < 4)
				grid2[i][j] += grid1[i][j];
			else
			{
				grid2[i][j] += grid1[i][j] - 4;
				if (i > 0)
					grid2[i - 1][j] += 1;
				if (j > 0)
					grid2[i][j - 1] += 1;
				if (i < 2)
					grid2[i + 1][j] += 1;
				if (j < 2)
					grid2[i][j + 1] += 1;
			}
		}
	}
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid2[i][j];
	return (1);
}

/**
* check_stable - checks if the sandpile is stable
* @grid: the grid to check
* Return: 1 if stable else 0
*/
int check_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
* print_grid - prints the grid
* @grid: grid to print
* Return: void
*/
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
