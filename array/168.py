from typing import List
import math


def containsNearbyDuplicate(nums: List[int], k: int) -> bool:
    stats = {}

    for index, value in enumerate(nums):
        if value in stats and abs(stats[value] - index) <= k:
            return True
        else:
            stats[value] = index

    return False


print(containsNearbyDuplicate([1, 2, 3, 1], 3))
