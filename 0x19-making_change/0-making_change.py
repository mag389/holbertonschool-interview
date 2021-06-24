#!/usr/bin/python3
""" making change """
import numpy as np


def makeChange(coins, total):
    """ makes change for total amount from coin values in coins """
    if type(total) is not int:
        return 0
    if type(coins) is not list or len(coins) <= 0:
        return 0
    if total <= 0:
        return 0
    if total in coins:
        return 1
    else:
        # print("in else")
        # minCoins = np.zeros(total + 1)
        minCoins = [-1] * (total + 1)
        minCoins[0] = 0
        usedCoins = [-1] * (total + 1)
        usedCoins[0] = 0
        for cents in range(total + 1):
            coincount = cents
            countchanged = 0
            newcoin = 0
            for j in [c for c in coins if c <= cents]:
                if (minCoins[cents - j] + 1 <= coincount and
                        minCoins[cents - j] != -1):
                    countchanged = 1
                    coincount = minCoins[cents - j] + 1
                    newcoin = j
            if countchanged == 1:
                minCoins[cents] = coincount
                usedCoins[cents] = newcoin
    # print(minCoins[total])
    # print(usedCoins)
    # totally = minCoins[total]
    totally = total
    while totally > 0:
        # print("used {}".format(totally))
        if usedCoins[totally] < 0:
            # print("return in while")
            return -1
        totally -= usedCoins[totally]
    return minCoins[total]
