#!/usr/bin/python3
"""module with minOperations function"""


def minOperations(n):
    """finds min operations to paste n number of Hs into a file using only
    Copy All and Paste operations.

    this algorithm is redundant but it works because any number's prime
    factors come before it in the loop.

    it works fine for reasonably small numbers and is a win for readability
    imo. would factor out the prime numbers if performance became an issue."""

    numOps = 0
    for i in range(2, n // 2 + 1):
        while n % i == 0:
            numOps += i
            n = n / i
    return numOps
