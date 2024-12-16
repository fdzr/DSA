from typing import List
import heapq


def sort_k_sorted_array(arr: List, k: int):
    heap = []

    for index in range(0, k + 1):
        heapq.heappush(heap, arr[index])

    i = 0
    for index in range(k + 1, len(arr)):
        arr[i] = heapq.heappop(heap)
        i += 1

        heapq.heappush(heap, arr[index])

    while len(heap) > 0:
        arr[i] = heapq.heappop(heap)
        i += 1

    return arr


arr = [3, 4, 1, 2, 6, 7, 5, 10, 8, 9]
print(sort_k_sorted_array(arr, 2))
