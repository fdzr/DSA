from typing import List


def min_number(nums1: List[int], nums2: List[int]) -> int:
    digit1 = min(nums1)
    digit2 = min(nums2)

    if digit1 == digit2:
        return digit1

    digit_set_1 = set(nums1)
    digit_set_2 = set(nums2)

    if res := digit_set_1.intersection(digit_set_2):
        return min(res)

    num1 = digit2 * 10 + digit1
    num2 = digit1 * 10 + digit2

    return min(num1, num2)


print(min_number([3,5,2,6], [3,1,7]))