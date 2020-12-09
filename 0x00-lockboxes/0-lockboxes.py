#!/usr/bin/python3
"""opening lockboxes module file"""


def canUnlockAll(boxes):
    """return true if all boxes can be unlocked, else false"""
    if not boxes:
        return False
    locked = [x for x in range(len(boxes))]
    locked[0] = 0
    # print(locked)
    locked = canUnlock(boxes, locked, 0)
    # print("--------")
    # print(locked)
    if sum(locked) == 0:
        return True
    return False


def canUnlock(boxes, locked, curIndex):
    """determines lockednedd recursively, returns a list of locked boxes"""
    # print(locked)
    locked[curIndex] = 0
    for key in boxes[curIndex]:
        if key < len(boxes) and locked[key] != 0:
            locked = canUnlock(boxes, locked, key)
    return locked
