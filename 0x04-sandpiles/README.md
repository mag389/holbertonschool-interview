# Sand piles!

a sand pile is a 2 dimensional matrix of the numbers 0-3
they can be added together elementwise.
if two sandpiles are added together and an element is above four the
    pile "topples" and four grains of sand move to adjacent squares.

for more info: Sandpiles - Numberphile https://www.youtube.com/watch?v=1MtEUErz7Gg

the main file to make program is 0-main.c
the header containing funciton prototypes is sandpiles.h
the file with functions is 0-sandpiles.c

to compile and run:
    gcc -Wall -Wextra -Werror -pedantic 1-main.c 0-sandpiles.c -o 0-sandpiles
and run with:
    ./0-sandpiles
