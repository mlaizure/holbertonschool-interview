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
    valid_codes = [200, 301, 400, 401, 403, 404, 405, 500]
    total_size = 0

    for line in sys.stdin:
        line_count += 1
        if line_count == 10:
            print_info(total_size, status_counts)
            line_count = 0

        line_parts = line.split()

        try:
            int(line_parts[-2])
            if int(line_parts[-2]) in valid_codes:
                status_counts[line_parts[-2]] += 1
        except (ValueError, IndexError):
            pass

        try:
            int(line_parts[-1])
            total_size += int(line_parts[-1])
        except (ValueError, IndexError):
            pass

    print_info(total_size, status_counts)

except KeyboardInterrupt:
    print_info(total_size, status_counts)
