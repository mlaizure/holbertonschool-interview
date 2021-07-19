#!/usr/bin/python3.4
"""lockboxes algorithm"""


def canUnlockAll(boxes):
    """determines if all the boxes can be opened"""
    num_boxes = len(boxes)
    found_keys = []
    for key in boxes[0]:
        if key in range(1, num_boxes):
            found_keys.append(key)
    for key in found_keys:
        for sub_key in boxes[key]:
            if sub_key not in found_keys and sub_key in range(1, num_boxes):
                found_keys.append(sub_key)
    return all(open_box in found_keys for open_box in range(1, num_boxes))
#    for i in range(1, num_boxes):
#        if i not in found_keys:
#            return False
#    return True
