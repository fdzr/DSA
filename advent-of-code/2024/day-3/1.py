import re
import functools


def process_data():
    with open("input.txt", "r") as f_in:
        for line in f_in:
            yield line


def process_numbers(patterns: list):
    return sum(
        functools.reduce(lambda x, y: x * y, map(int, re.findall(r"\d+", p)))
        for p in patterns
    )


def first_part():
    sum = 0

    for line in process_data():
        patterns = re.findall(r"mul\(\d{1,3},\d{1,3}\)", line)
        sum += process_numbers(patterns)

    return sum


print(first_part())
