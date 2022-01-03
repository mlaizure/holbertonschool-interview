#!/usr/bin/python3
"""module with rotate_2d_matrix function"""


def rotate_2d_matrix(matrix):
    """rotates a 2D matrix 90 degrees"""
    new_matrix = [[0 for x in range(len(matrix))] for y in range(len(matrix))]
    i = -1
    for row in matrix:
        i += 1
        j = 0
        for item in row:
            new_matrix[i][j] = item
            j += 1

    j = len(matrix)
    for row in new_matrix:
        i = 0
        j -= 1
        for item in row:
            matrix[i][j] = item
            i += 1
