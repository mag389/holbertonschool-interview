#!/usr/bin/python3
"""
Making change file
"""


def makeChange(coins, total):
    if total <= 0:
        return 0
    goal = 0
    usedCoins = 0

    for c in reversed(sorted(coins)):
        while goal + c <= total:
            usedCoins += 1
            goal += c

    if goal != total:
        return -1
    return usedCoins
