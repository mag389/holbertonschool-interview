#!/usr/bin/python3
""" pascal's triangle """


def pascal_triangle(n):
    """ makes a pascal triangle """
    if n <= 0:
        return []
    if n == 1:
        return [[1]]
    if n == 2:
        return [[1], [1, 1]]
    """ else"""
    newlist = [1 for i in range(0, n)]
    oldlist = pascal_triangle(n-1)
    oldlist.append(newlist)
    for i in range(1, n-1):
        newlist[i] = oldlist[n - 2][i] + oldlist[n-2][i - 1]
    return oldlist
