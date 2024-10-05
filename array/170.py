from typing import List


def missingNumber(nums: List[int]) -> int:
    sum = 0
    n = len(nums)

    for elem in nums:
        sum += elem

    return n * (n + 1) // 2 - sum


print(missingNumber([9, 6, 4, 2, 3, 5, 7, 0, 1]))
