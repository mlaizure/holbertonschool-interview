#!/usr/bin/python3
"""Module with function that returns lists of ints representing Pascal's
triangle of n"""


def pascal_triangle(n):
    """returns lists of ints representing Pascal's triangle of n"""
    if n <= 0:
        return []
    triangle = [[1]]
    for i in range(2, n + 1):
        l = triangle[i - 2]
        row = [1] + [a + b for (a, b) in zip(l, l[1:])] + [1]
        triangle.append(row)
    return triangle
