#!/usr/bin/python3
"""opening lockboxes module file"""


def canUnlockAll(boxes):
    """return true if all boxes can be unlocked, else false"""
    if not boxes:
        return False
    locked = [1 for x in range(len(boxes))]
    locked[0] = 0
    locked = canUnlock(boxes, locked, 0)
    if sum(locked) == 0:
        return True
    return False


def canUnlock(boxes, locked, curIndex):
    """determines lockednedd recursively, returns a list of locked boxes"""
    locked[curIndex] = 0
    for key in boxes[curIndex]:
        if key > len(boxes):
            continue
        if locked[key] == 1:
            locked = canUnlock(boxes, locked, key)
    return locked
