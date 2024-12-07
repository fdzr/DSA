from typing import List


def safe_report(nums: List):
    desc, asc = False, False

    for index in range(1, len(nums)):
        if nums[index] == nums[index - 1]:
            return False
        if not abs(nums[index] - nums[index - 1]) in [1, 2, 3]:
            return False
        if nums[index] > nums[index - 1]:
            asc = True
        if nums[index] < nums[index - 1]:
            desc = True

    if asc is True and desc is True:
        return False

    return True


def check_unsafe_report(nums: List):
    for i in range(len(nums)):
        nums_aux = nums[:i] + nums[i + 1 :]
        if safe_report(nums_aux) is True:
            return True

    return False


def process_data():
    sum = 0

    with open("input.txt", "r") as f_in:
        for line in f_in:
            yield line


def first_part():
    sum = 0
    for line in process_data():
        nums = list(map(int, line.split()))
        sum += safe_report(nums)

    return sum


def second_part():
    sum = 0
    for line in process_data():
        nums = list(map(int, line.split()))
        if safe_report(nums) or check_unsafe_report(nums):
            sum += 1

    return sum


print(first_part())
print(second_part())
