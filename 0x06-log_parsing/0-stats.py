#!/usr/bin/python3
""" script that reads stdin line by line and computes metrics"""
import sys


try:
    line_count = -1
    status_counts = {'200': 0, '301': 0, '400': 0, '401': 0, '403': 0,
                     '404': 0, '405': 0, '500': 0}
    total_size = 0

    for line in sys.stdin:
        skip = False
        line_count += 1
        if line_count == 10:
            print("File size: {}".format(total_size))
            for key, value in sorted(status_counts.items()):
                print("{}: {}".format(key, value))
            line_count = 0

        if '[' in line and ']' in line:
            before_date = line.split('[')[0]
            after_date = line.split(']')[1]
            line_parts = (before_date + after_date).split()
        else:
            continue

        ip = line_parts[0].split('.')
        if len(ip) != 4:
            continue
        for num in ip:
            try:
                int(num)
            except:
                skip = True
                break
            if int(num) not in range(1, 256):
                skip = True
                break
        if skip:
            continue

        if line_parts[1] != "-":
            continue

        if line_parts[2] != '"GET' \
           or line_parts[3] != '/projects/260' \
                               or line_parts[4] != 'HTTP/1.1"':
            continue

        try:
            int(line_parts[5])
        except:
            continue
        if int(line_parts[5]) not in [200, 301, 400, 401, 403, 404, 405, 500]:
            continue

        try:
            int(line_parts[6])
        except:
            continue

        status_counts[line_parts[5]] += 1
        total_size += int(line_parts[6])

except KeyboardInterrupt:
    print("File size: {}".format(total_size))
    for key, value in sorted(status_counts.items()):
        print("{}: {}".format(key, value))
