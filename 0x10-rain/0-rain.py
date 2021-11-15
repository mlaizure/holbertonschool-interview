#!/usr/bin/python3
"""module that calculates rain water area"""


def rain(walls):
    """function that caluclates rain water area"""
    if not walls:
        return 0
    water = 0
    for idx, wall_height in enumerate(walls):
        left_max = max(walls[:idx + 1])
        right_max = max(walls[idx:])
        small_wall = min(left_max, right_max)
        water += max(0, small_wall - wall_height)
    return water
