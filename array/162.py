from typing import List


def search(nums: List[int], target: int) -> int:
    L, R = 0, len(nums) - 1

    while L <= R:
        M = L + (R - L) // 2

        if nums[M] == target:
            return M

        if nums[L] <= nums[M]:
            if nums[L] <= target <= nums[M]:
                R = M - 1
            else:
                L = M + 1
        else:
            if nums[M] <= target <= nums[R]:
                L = M + 1
            else:
                R = M - 1

    return -1


print(search([1], 0))