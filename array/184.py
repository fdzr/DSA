from typing import List


def specialArray(nums: List[int]) -> int:
    cant = len(nums)
    nums.sort()

    for index in range(len(nums)):
        if nums[index] == 0:
            cant -= 1
            continue

        if nums[index] >= cant and index - 1 > 0 and nums[index - 1] < cant:
            break

        if nums[index] >= cant and index - 1 < 0:
            break

        cant -= 1

    if cant != 0:
        return cant
    else:
        return -1


print(specialArray([0, 4, 3, 0, 4]))
