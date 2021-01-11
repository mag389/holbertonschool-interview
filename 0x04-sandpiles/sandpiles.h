#ifndef SANDPILES_H
#define SANDPILES_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int topple_grid(int grid1[3][3], int grid2[3][3]);
int check_stable(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
/*
* static void print_grid_sum(int grid1[3][3], int grid2[3][3]);
* static void print_grid(int grid[3][3]);
*/

#endif
