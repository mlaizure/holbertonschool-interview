#include "menger.h"

/**
 * menger - draws a 2-D Menger sponge
 * @level: level of sponge to draw
 * Return: none
 */

void menger(int level)
{
	const int size = pow(3, level);
	int i, j, l;

	if (level < 0)
		return;
	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			int is_blank = 0;

			for (l = 0; l < level; ++l)
				if ((i / (int)pow(3, l)) % 3 == 1 && (j / (int)pow(3, l)) % 3 == 1)
					is_blank = 1;
			if (is_blank)
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
