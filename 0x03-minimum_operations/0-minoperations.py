#!/usr/bin/python3
"""minoperations file"""


def minOperations(n):
    """minimum copy paste operations to make a character repeat n times"""
    if not isinstance(n, int):
        return 0
    if n <= 1:
        return 0
    for i in range(2, n + 1):
        if n % i == 0:
            return 1 + (i - 1) + minOperations(int(n / i))
    return (n + 1)
