from typing import List
from collections import Counter


def containsDuplicate(nums: List[int]) -> bool:
    freq = Counter(nums)

    for elem, count in freq.items():
        if count > 1:
            return True

    return False


print(containsDuplicate([1, 1, 1, 3, 3, 4, 3, 2, 4, 2]))
