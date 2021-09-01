#!/usr/bin/python3
""" script that reads stdin line by line and computes metrics"""
import sys


def print_info(total_size, status_counts):
    print("File size: {}".format(total_size))
    for key, value in sorted(status_counts.items()):
        if value > 0:
            print("{}: {}".format(key, value))

try:
    line_count = -1
    status_counts = {'200': 0, '301': 0, '400': 0, '401': 0, '403': 0,
                     '404': 0, '405': 0, '500': 0}
    total_size = 0

    for line in sys.stdin:
        skip = False
        line_count += 1
        if line_count == 10:
            print_info(total_size, status_counts)
            line_count = 0

        line_parts = line.split()

        try:
            int(line_parts[-2])
            status_counts[line_parts[-2]] += 1
        except:
            pass

        try:
            int(line_parts[-1])
            total_size += int(line_parts[-1])
        except:
            pass

    print_info(total_size, status_counts)

except KeyboardInterrupt:
    print_info(total_size, status_counts)
