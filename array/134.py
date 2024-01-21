import heapq
from typing import List


def findKthLargest(nums: List[int], k: int) -> int:
    li = nums
    heapq.heapify(li)

    return heapq.nlargest(k, li)[-1]


nums = [3, 2, 3, 1, 2, 4, 5, 5, 6]
k = 4

print(findKthLargest(nums, k))
