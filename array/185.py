import heapq
from typing import List


def get_maximum_profit(seats: List, N: int):
    pq = []
    max_profit = 0

    for elem in seats:
        heapq.heappush(pq, -elem)

    for index in range(N):
        if pq:
            price = heapq.heappop(pq)
            max_profit += abs(price)

            heapq.heappush(pq, -1 * (abs(price) - 1))

    return max_profit


N = 3
print(get_maximum_profit([1, 2, 4], N))
