#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdio.h>
#include <stdlib.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT -1

int slide_line(int *line, size_t size, int direction);
/*
* static void print_array(int const *array, size_t size);
*/

#endif