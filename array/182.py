from typing import List
import heapq
import math


def pickGifts(gifts: List[int], k: int) -> int:
    l1 = [-num for num in gifts]
    heapq.heapify(l1)

    while k > 0:
        elem = -heapq.heappop(l1)
        heapq.heappush(l1, -math.floor(math.sqrt(elem)))
        k -= 1

    return abs(sum(l1))


print(
    pickGifts([25, 64, 9, 4, 1000000000, 1000000000, 999999999, 12232323, 3434344], 4)
)
