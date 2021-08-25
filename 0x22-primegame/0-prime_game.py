#!/usr/bin/python3
""" prime game """


def isWinner(x, nums):
    """ determines the winner of the prime game
        x: number of rounds
        nums: array of n
        Return: name of the winner
            or None if undetermined
        n and x both <= 10000
    """
    if x <= 2 or nums == None
        return None
    ben, maria = 0, 0
    a = [1 for x in range(sorted(nums)[-1])]
    a[0], a[1] = 0, 0
    for i in range(2, len(a)):
        remove_multiples(a, i)
    # print(a)
    # print(nums)
    for i in nums:
        if sum(a[0:i]) % 2 == 0:
            ben += 1
        else:
            maria += 1
    if ben > maria:
        return "Ben"
    if maria > ben:
        return "Maria"
    return None


def remove_multiples(listy, x):
    """ removes multiples of a prime from a list
        listy: list to remove from
        x: the prime to remove
    """
    for i in range(2, len(listy)):
        try:
            listy[i * x] = 0
        except (ValueError, IndexError):
            break
