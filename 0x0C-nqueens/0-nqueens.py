#!/usr/bin/python3
"""program that solves N queens puzzle"""
import sys


def get_n():
    """validates command line input"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    return n



if __name__ == "__main__":
    get_n()
