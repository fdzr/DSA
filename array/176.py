from typing import List


def sortArrayByParity(nums: List[int]) -> List[int]:
    L, R = 0, len(nums) - 1

    while L <= R:
        if nums[L] % 2 == 0:
            L += 1
            continue
        if nums[R] % 2 == 1:
            R -= 1
            continue

        nums[L], nums[R] = nums[R], nums[L]
        L += 1
        R -= 1

    return nums


print(sortArrayByParity([3, 1, 2, 4]))
