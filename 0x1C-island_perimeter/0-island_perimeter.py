#!/usr/bin/python3
"""Module with island perimeter function"""


def island_perimeter(grid):
    """returns the perimeter of the island described in grid"""
    perimeter = 0
    for row_num, row in enumerate(grid):
        for count, value in enumerate(row):
            if value == 1:
                if count == 0 or row[count - 1] == 0:
                    perimeter += 1
                if count == len(row) - 1 or row[count + 1] == 0:
                    perimeter += 1
                if row_num == 0 or grid[row_num - 1][count] == 0:
                    perimeter += 1
                if row_num == len(grid) - 1 or grid[row_num + 1][count] == 0:
                    perimeter += 1
    return perimeter
