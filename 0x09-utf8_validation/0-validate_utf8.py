#!/usr/bin/python3
""" utf-8 validaiton """


def validUTF8(data):
    """ determines if data is valid utf-8
        data: list of integers
        returns: True if valid encode else false
    """
    numbytes = 0
    for number in data:
        if numbytes == 0:
            if number >= 0 and number <= 128:
                continue
            if number <= 223:
                numbytes += 1
                continue
            if number <= 239:
                numbytes += 2
                continue
            if number <= 255:
                numbytes += 3
                continue
            return False
        if number >= 128 and number <= 191:
            numbytes -= 1
            continue
        else:
            return False
    if numbytes == 0:
        return True
    return False
