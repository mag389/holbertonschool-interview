#!/usr/bin/python3
""" rain in buckets problem """


def rain(walls):
    """ how much water will be retained by walls
        list of non-negative integers
    """
    if type(walls) is not list or len(walls) <= 0:
        return 0
    # print(walls)
    if len(walls) == 1:
        return 0
    # check for length of two?
    if walls[0] == 0:
        return rain(walls[1:])
    if walls[0] == max(walls):
        # print("shortening")
        walls[0] = max(walls[1:])
        # print(walls)
        idx = walls[1:].index(walls[0])
    for i in range(1, len(walls)):
        if walls[i] >= walls[0]:
            tmp = walls[0] * i - sum(walls[:i])
            break
    return tmp + rain(walls[i:])
