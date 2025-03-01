from typing import List


def applyOperations(nums: List[int]) -> List[int]:
    n = len(nums)
    for index in range(n - 1):
        if nums[index] == nums[index + 1]:
            nums[index] *= 2
            nums[index + 1] = 0

    L, R = 0, 1

    while R < n:
        if nums[L] != 0:
            L += 1
            R = L + 1
            continue
        if nums[R] != 0:
            nums[L], nums[R] = nums[R], nums[L]
            L += 1
            R += 1
        else:
            R += 1

    return nums


if __name__ == "__main__":
    nums = [0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 11, 12, 12]
    applyOperations(nums)
    print(nums)
