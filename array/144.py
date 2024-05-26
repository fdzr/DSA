from collections import Counter
from typing import List


def sortColors(nums: List[int]) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """

    freq = Counter(nums)
    index = 0

    for key in [0, 1, 2]:
        cant = freq[key]
        while cant > 0:
            nums[index] = key
            cant -= 1
            index += 1


nums = [2, 0, 1]
sortColors(nums)
print(nums)
