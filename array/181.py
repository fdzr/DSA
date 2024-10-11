from typing import List


def dominantIndex(nums: List[int]) -> int:
    largest, second = 0, 0
    index_largest_num = 0

    for index, value in enumerate(nums):
        if value > largest:
            second = largest
            largest = value
            index_largest_num = index
        elif value > second:
            second = value

    if largest >= second * 2:
        return index_largest_num
    else:
        return -1


print(dominantIndex([1, 2, 3, 4]))
