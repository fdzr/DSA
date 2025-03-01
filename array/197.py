from typing import List


def moveZeroes(nums: List[int]) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """

    L, R = 0, 1

    while R < len(nums):
        if nums[L] != 0:
            L += 1
            R = L + 1
            continue
        if nums[R] != 0:
            nums[L], nums[R] = nums[R], nums[L]
            R += 1
            L += 1
        else:
            R += 1


def moveZeroes2(nums: List[int]):
    nums.sort(key=lambda x: x == 0)


nums = [0, 1, 0, 3, 12]
moveZeroes2(nums)

print(nums)
