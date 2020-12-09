#!/usr/bin/python3
"""lockbox intervew question"""


def canUnlockAll(boxes):
    """uses a queue to search for all boxes"""
    if not boxes:
        return False

    n = len(boxes)
    keys = [0]

    for key in keys:
        for box in boxes[key]:
            if box < len(boxes) and box not in keys:
                keys.append(box)

    return len(keys) == len(boxes)
