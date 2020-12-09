#!/usr/bin/python3
"""opening lockboxes module file"""


def canUnlockAll(boxes):
    """return true if all boxes can be unlocked, else false"""
    if not boxes:
        return False
    return len(dfs(boxes, [])) == len(boxes)

    # locked = [x for x in range(len(boxes))]
    # locked[0] = 0
    # print(locked)
    # locked = canUnlock(boxes, locked, 0)
    # print("--------")
    # print(locked)
    # if sum(locked) == 0:
    #     return True
    # return False


def dfs(boxes, path, source=0):
    path += [source]
    for k in boxes[source]:
        if k < len(boxes) and k not in set(path):
            dfs(boxes, path, k)
    return path


def canUnlock(boxes, locked, curIndex):
    """determines lockednedd recursively, returns a list of locked boxes"""
    # print(locked)
    locked[curIndex] = 0
    for key in boxes[curIndex]:
        if key < len(boxes) and locked[key] != 0:
            locked = canUnlock(boxes, locked, key)
    return locked
