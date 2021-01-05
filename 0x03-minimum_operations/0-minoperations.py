#!/usr/bin/env python3
"""minoperations file"""


def minOperations(n):
    """minimum copy paste operations to make a character repeat n times"""
    # print("entering the function for n={}".format(n))
    if not isinstance(n, int):
        return 0
    if n <= 1:
        return 0
    # if n == 2:
    #     return 2
    for i in range(2, n + 1):
        if n % i == 0:
            # print("we found a factor for {} it's {}".format(n, i))
            # if n == i:
            #    return 1 + n / i
            # this if statemnt wasn't needed because if n == i it's ignored in
            # the base case
            return 1 + (i - 1) + minOperations(int(n / i))
            # the first 1 represents the copy all operation
            # the i - i represents how many times to paste the current string
    return (n + 1)
