# code provided by Borodi Bogdan

from random import randint
import time


def generate_list(n: int) -> list:
    List = []

    List.append(randint(0, 100))

    for index in range(1, n):
        List.append(List[index - 1] + randint(1, 100))

    return List


def TestSearch():
    for i in range(0, 1000):
        length = randint(10, 10000)
        list = generate_list(length)
        key = randint(0, 100000)

        s_pos = 2 ** (Exponential_Search(list, key) - 1) - 1
        e_pos = 2 ** (Exponential_Search(list, key)) - 1

        res = Binary_Search(list, key, s_pos, e_pos)

        print("List length is: " + str(length) + " and the index of the key is: " + str(res))

    # generates 1000 lists and tests the implementation of exponential


def Binary_Search(data: list, key: int, left: int, right: int):
    # binary search for key between left right, -1 not
    while (left <= right):
        mid = (left + right) // 2

        if (data[mid] < key):
            left = mid + 1
        elif (data[mid] > key):
            right = mid - 1
        else:
            return mid
    return -1


def Exponential_Search(data: list, key: int):
    # ascending
    # we search for the key
    i = 0
    length = len(data)

    while ((2 ** i) - 1 <= length - 1):
        where = 2 ** i - 1

        if (where <= length - 1):
            if (data[where] > key):
                return i

        i += 1

    return (i - 1)


TestSearch()

print("All tests passed")

# 0 ^ 10 = 0
# 1 ^ 10 = 1
# 1.5 ^10 = 57-ish
# 2 ^10 = 1024

#Borodi Bogdan

def root_calc(x: int, r: int, p: float) -> float:
    """
    Determine the r-th root of positive integer x
    :param x: positive integer
    :param r: positive integer
    :param p: positive float
    :return: res so that x - p <= res ** r <= x + p
    """
    # TODO Keep in mind whether x in [0, 1) or in [1, ..)

    left = 0.0001
    e = 0.000001
    right = x

    if(x <= 1 and x >= 0):
        left, right = right, left


    while(left <= right):
        mid = (left + right) / 2

        if(x - p <= mid ** r and x + p >= mid ** r):
            return mid
        elif (x - p >= mid ** r):
            left = mid + e
        else:
            right = mid - e

    return -1


