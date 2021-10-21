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


def row_has_queen(board, row):
    """check row for other queens"""
    for has_queen in board[row]:
        if has_queen:
            return True
    return False


def col_has_queen(board, col):
    """check col for other queens"""
    n = len(board[0])
    for row in range(n):
        has_queen = board[row][col]
        if has_queen:
            return True
    return False


def diag_has_queen(board, row, col):
    """check diagonals for queens"""
    for i, j in zip(range(row, -1, -1),
                    range(col, -1, -1)):
        if board[i][j]:
            return True

    for i, j in zip(range(row, len(board[0]), 1),
                    range(col, -1, -1)):
        if board[i][j]:
            return True

    return False


def print_board(board, n):
    """prints the board"""
    queens = [[i, j] for i in range(n) for j in range(n) if board[i][j]]
    print(queens)


def n_queens():
    """make board"""
    n = get_n()
    board = [[False for j in range(n)] for i in range(n)]
    solve_nqueens(0, 0, board)


def solve_nqueens(idx, queens_found, board):
    """recursive backtracking"""
    n = len(board[0])
    ijs = [(j, i) for j in range(n) for i in range(n)]
    if queens_found == n:
        print_board(board, n)
        return True
    elif idx >= len(ijs):
        return False
    i, j = ijs[idx]
    if not row_has_queen(board, i) and not col_has_queen(board, j) \
       and not diag_has_queen(board, i, j):
        queens_found += 1
    b_true = [row[:] for row in board]
    b_false = [row[:] for row in board]
    b_true[i][j] = True
    b_false[i][j] = False
    if solve_nqueens(idx + 1, queens_found, b_true) or \
       solve_nqueens(idx + 1, queens_found, b_false):
        return True


if __name__ == "__main__":
    n_queens()
