#!/usr/bin/python3
"""lockbox intervew question"""


def canUnlockAll(boxes):
    """
    Method that determines if all the boxes can be opened.
    """
    if not boxes:
        return False

    n = len(boxes)
    keys = [0]

    for key in keys:
        for box in boxes[key]:
            if box < n and box not in keys:
                keys.append(box)

    if len(keys) != n:
        return False
    return True
