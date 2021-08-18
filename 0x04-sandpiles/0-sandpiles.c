#include "sandpiles.h"

/**
 * check_stable - checks if sand piles are stable, prints grid if now
 * @sum: the current grid
 * Return: none
 */

void check_stable(int sum[3][3])
{
	int i, j, is_stable = 1;

	for (i = 0; i < 3 && is_stable; ++i)
		for (j = 0; j < 3 && is_stable; ++j)
			if (sum[i][j] > 3)
				is_stable = 0;
	if (!is_stable)
	{
		printf("=\n");
		for (i = 0; i < 3; ++i)
		{
			for (j = 0; j < 3; ++j)
			{
				if (j)
					printf(" ");
				printf("%d", sum[i][j]);
			}
			printf("\n");
		}
		cascade_top(sum);
	}
}

/**
 * cascade_top - toppling the top row of sand piles
 * @sum: the current grid
 * Return: none
 */

void cascade_top(int sum[3][3])
{
	int i, j, prev[3][3];

	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)
			prev[i][j] = sum[i][j];
	if (prev[0][0] > 3)
	{
		sum[0][0] = sum[0][0] - 4;
		sum[0][1] = sum[0][1] + 1;
		sum[1][0] = sum[1][0] + 1;
	}
	if (prev[0][1] > 3)
	{
		sum[0][1] = sum[0][1] - 4;
		sum[0][0] = sum[0][0] + 1;
		sum[0][2] = sum[0][2] + 1;
		sum[1][1] = sum[1][1] + 1;
	}
	if (prev[0][2] > 3)
	{
		sum[0][2] = sum[0][2] - 4;
		sum[0][1] = sum[0][1] + 1;
		sum[1][2] = sum[1][2] + 1;
	}
	cascade_mid(prev, sum);
}

/**
 * cascade_mid - toppling the middle row of sand piles
 * @prev: the previous grid
 * @sum: the current grid
 * Return: none
 */

void cascade_mid(int prev[3][3], int sum[3][3])
{
	if (prev[1][0] > 3)
	{
		sum[1][0] = sum[1][0] - 4;
		sum[0][0] = sum[0][0] + 1;
		sum[2][0] = sum[2][0] + 1;
		sum[1][1] = sum[1][1] + 1;
	}
	if (prev[1][1] > 3)
	{
		sum[1][1] = sum[1][1] - 4;
		sum[0][1] = sum[0][1] + 1;
		sum[1][0] = sum[1][0] + 1;
		sum[2][1] = sum[2][1] + 1;
		sum[1][2] = sum[1][2] + 1;
	}
	if (prev[1][2] > 3)
	{
		sum[1][2] = sum[1][2] - 4;
		sum[0][2] = sum[0][2] + 1;
		sum[2][2] = sum[2][2] + 1;
		sum[1][1] = sum[1][1] + 1;
	}
	cascade_bottom(prev, sum);
}

/**
 * cascade_bottom - toppling the bottom row of sand piles
 * @prev: the previous grid
 * @sum: the current grid
 * Return: none
 */

void cascade_bottom(int prev[3][3], int sum[3][3])
{
	if (prev[2][0] > 3)
	{
		sum[2][0] = sum[2][0] - 4;
		sum[1][0] = sum[1][0] + 1;
		sum[2][1] = sum[2][1] + 1;
	}
	if (prev[2][1] > 3)
	{
		sum[2][1] = sum[2][1] - 4;
		sum[2][0] = sum[2][0] + 1;
		sum[2][2] = sum[2][2] + 1;
		sum[1][1] = sum[1][1] + 1;
	}
	if (prev[2][2] > 3)
	{
		sum[2][2] = sum[2][2] - 4;
		sum[1][2] = sum[1][2] + 1;
		sum[2][1] = sum[2][1] + 1;
	}
	check_stable(sum);
}

/**
 * sandpiles_sum - computes sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 * Return: none
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)
			grid1[i][j] += grid2[i][j];

	check_stable(grid1);
}
