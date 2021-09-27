#include "slide_line.h"

/**
 * merge - adds current value to end value and sets current value to 0
 * @line: pointer to array of ints
 * @i: index of value to merge
 * @end: index of value to merge into
 * Return: none
 */

void merge(int *line, int i, int end)
{
	line[end] += line[i];
	line[i] = 0;
}

/**
 * slide_line - given an array of ints, slide and merge to left or right
 * @line: pointer to array of ints
 * @size: number of elements in line
 * @direction: left or right
 * Return: 1 on successful slide and merge, otherwise 0
 */

int slide_line(int *line, size_t size, int direction)
{
	int i = 0, end = 0;

	if (size == 0 || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
	{
		for (i = 1; i < (int)size; ++i)
		{
			if (line[i] != 0 && line[i] == line[end])
				merge(line, i, end++);
			else if (line[i] != 0 && line[i] != line[end])
			{
				if (line[end] != 0)
					end++;
				if (line[end] == 0)
					merge(line, i, end);
			}
		}
	}
	else
	{
		end = (int)size - 1;
		for (i = (int)size - 2; i >= 0; --i)
		{
			if (line[i] != 0 && line[i] == line[end])
				merge(line, i, end--);
			else if (line[i] != 0 && line[i] != line[end])
			{
				if (line[end] != 0)
					end--;
				if (line[end] == 0)
					merge(line, i, end);
			}
		}
	}
	return (1);
}
