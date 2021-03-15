#!/usr/bin/python3
import sys


# print(str(sys.argv))
# print(len(sys.argv))
def nqueen(arr, n):
    """ place the queens
        location are in the arr array
        n is queens placed so far
    """
    if n == 0:
        for i in range(len(arr)):
            arr[0] = [0, i]
            nqueen(arr, n + 1)
    elif n == len(arr):
        print(arr)
        return
    else:
        # tmp = next_open(arr, n)
        next_open(arr, n)
        # print(tmp)
        # print(arr)
        # if tmp[0] == -1:
        #     print(tmp)
        #     return
        # arr[n] = tmp
        # nqueen(arr, n + 1)
        # return nqueen(arr, n + 1)


def next_open(arr, n):
    """ find next open spot for a queen """
    potential = [n, 0]
    attacked = 0
    for i in range(0, len(arr)):
        attacked = 0
        potential[1] = i
        for ind in range(n):
            prev_q = arr[ind]
            if prev_q[0] == potential[0]:
                attacked = 1
                break
            if prev_q[1] == potential[1]:
                attacked = 1
                break
            if prev_q[1] + prev_q[0] == potential[1] + potential[0]:
                attacked = 1
                break
            if prev_q[0] - prev_q[1] == potential[0] - potential[1]:
                attacked = 1
                break
        if attacked == 0:
            arr[n] = potential
            nqueen(arr, n + 1)
            # return potential
    # if (potential[1] == 5):
        # print(potential)
    return [-1, potential[1]]


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    try:
        N = int(sys.argv[1])
    except Exception as e:
        print("N must be a number")
        exit(1)

    if N < 4:
        print("N must be at least 4")
        exit(1)

    # print("nqueens results:")
    arr = [[0, 0] for _ in range(N)]
    # print(arr)
    nqueen(arr, 0)
