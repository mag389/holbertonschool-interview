#!/usr/bin/python3
""" a scriptp for reading stdin """
import sys
import signal


counter = 0
filesize = 0
codes = [200, 301, 400, 401, 403, 404, 405, 500]
coded = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

"""
my initial method: had right ouput so i don't know why it failed
def interrupted(signal, frame):
    "" what to do when an interrupt signal is given ""
    print("File size: {}".format(filesize))
    for num in codes:
        if coded[int(num)] > 0:
            print(str(num) + ": " + str(coded[int(num)]))
    exit(0)
"""

# signal.signal(signal.SIGINT, interrupted)
try:
    for line in sys.stdin:
        words = line.split()
        # print("after split")
        # print("{}".format(len(words)))
        if len(words) != 9:
            raise Exception
        filesize += int(words[-1])
        code = int(words[-2])
        coded[code] += 1
        counter += 1
        if counter == 10:
            print("File size: {}".format(filesize))
            for num in range(len(codes)):
                if coded[int(codes[num])] > 0:
                    print(str(codes[num]) + ": " + str(coded[int(codes[num])]))
            counter = 0
except Exception:
    pass
finally:
    print("File size: {}".format(filesize))
    for num in range(len(codes)):
        if coded[int(codes[num])] > 0:
            print(str(codes[num]) + ": " + str(coded[int(codes[num])]))
