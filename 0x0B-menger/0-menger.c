#include "menger.h"
/**
* menger - prints the menger sponge
* @level: the level of sponge to draw
* Return: void, prints instead
*/
void menger(int level)
{
	int i, j, k, l = 0, m;

	/* printf("%i\n", 5 / 3); made sure math all right */
	if (level == 0)
		printf("#\n");
	else if (level > 0)
	{
		for (i = 0; i < pow(3, level); i++)
		{
			for (j = 0; j < pow(3, level); j++)
			{
				for (k = 0; k < level; k++)
				{
					l = 0;
					m = pow(3, k);
					if ((i / m % 3) == 1 && (j / m % 3) == 1)
					{
						printf(" ");
						l = 1;
						break;
					}
					/* printf("#"); useful for level = 1 */
				}
				if (l == 0)
				{
					printf("#");
				}
				/* printf("%i\n", m);*/
			}
			printf("\n");
		}
	}
}
