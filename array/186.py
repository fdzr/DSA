from typing import List


def nextPermutation(nums: List[int]) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """

    i, j = -1, -1
    valid = False

    for index in range(1, len(nums)):
        if nums[index] > nums[index - 1] and index > i:
            i = index
            valid = True

    if valid is False:
        nums.reverse()
        return

    for item in range(i, len(nums)):
        if nums[item] > nums[i - 1]:
            j = item

    nums[j], nums[i - 1] = nums[i - 1], nums[j]

    nums[i:] = reversed(nums[i:])


nums = [5, 4, 3, 2, 1]
nextPermutation(nums)
print(nums)
