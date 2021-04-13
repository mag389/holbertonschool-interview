#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))
    # 6
    walls = [1, 0, 3, 1, 2, 0, 2, 0]
    print(rain(walls))
    # 4
    walls = [0, 1, 0, 2, 0, 3, 0, 4, 4]
    print(rain(walls))
    # 6
