#!/usr/bin/python3
"""module with minOperations function"""
import math


def minOperations(n):
    """finds min operations to paste n number of Hs into a file using only
    Copy All and Past operations"""

    if n < 2:
        return 0

    primeFactors = []

    while n % 2 == 0:
        primeFactors.append(2)
        n = n // 2

    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            primeFactors.append(i)
            n = n // i

    if n > 2:
        primeFactors.append(n)

    return sum(primeFactors)

    """finds min operations to paste n number of Hs into a file using only
    Copy All and Paste operations.

    this algorithm is redundant but it works because any number's prime
    factors come before it in the loop.

    it works fine for reasonably small numbers and is a win for readability
    imo. would factor out the prime numbers if performance became an issue.

    numOps = 0
    for i in range(2, n // 2 + 1):
        while n % i == 0:
            numOps += i
            n = n / i
    return numOps
"""
