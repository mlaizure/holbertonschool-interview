#!/usr/bin/python3
"""function that checks if list of ints is valid utf-8 encoding"""


def readValidUTF8SuccessorBytes(data, size):
    """checks length and successor bytes for correct prefix"""
    if len(data) < size:
        return False
    for i in range(size):
        if not hasBitsPrefix(data[i], '10'):
            return False
    return data[size:]


def hasBitsPrefix(n, s):
    """checks if prefix is valid"""
    prefix = n >> (8 - len(s))
    return prefix == int(s, 2)


def readValidUTF8Char(data):
    """reads a character if valid"""
    if hasBitsPrefix(data[0], '0'):
        return data[1:]
    elif hasBitsPrefix(data[0], '110'):
        return readValidUTF8SuccessorBytes(data[1:], 1)
    elif hasBitsPrefix(data[0], '1110'):
        return readValidUTF8SuccessorBytes(data[1:], 2)
    elif hasBitsPrefix(data[0], '11110'):
        return readValidUTF8SuccessorBytes(data[1:], 3)
    else:
        return False


def validUTF8(data):
    """checks if data is valid utf-8 encoding"""
    while len(data):
        data = readValidUTF8Char(data)
        if data is False:
            return False
    return True
