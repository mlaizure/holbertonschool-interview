#!/usr/bin/python3
"""function that checks if list of ints is valid utf-8 encoding"""


def hasBitsPrefix(n, s):
    """checks if prefix is valid"""
    prefix = n >> (8 - len(s))
    return prefix == int(s, 2)


def readValidUTF8Char(data):
    """reads a character if valid"""
    try:
        if hasBitsPrefix(data[0], '0'):
            return data[1:]
        elif hasBitsPrefix(data[0], '110'):
            if not hasBitsPrefix(data[1], '10'):
                return False
            return data[2:]
        elif hasBitsPrefix(data[0], '1110'):
            if not hasBitsPrefix(data[1], '10') or not \
               hasBitsPrefix(data[2], '10'):
                return False
            return data[3:]
        elif hasBitsPrefix(data[0], '11110'):
            if not hasBitsPrefix(data[1], '10') or not \
               hasBitsPrefix(data[2], '10') or not \
               hasBitsPrefix(data[3], '10'):
                return False
            return data[4:]
        else:
            return False
    except IndexError:
        return False


def validUTF8(data):
    """checks if data is valid utf-8 encoding"""
    while len(data):
        data = readValidUTF8Char(data)
        if data is False:
            return False
    return True
