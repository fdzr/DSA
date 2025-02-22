from typing import List
import heapq
import math


def dijkstra(graph: List[List[int]], n: int, k: int, dist: List[int]):
    heap = []

    heapq.heappush(heap, (0, k))

    while len(heap) > 0:
        w, e = heapq.heappop(heap)

        for item in graph[e]:
            if dist[item[0]] > dist[e] + item[1]:
                dist[item[0]] = dist[e] + item[1]
                heapq.heappush(heap, (dist[item[0]], item[0]))


def networkDelayTime(times: List[List[int]], n: int, k: int) -> int:
    dist = [math.inf] * n
    dist[k - 1] = 0

    graph = [[] for _ in range(n)]

    for we in times:
        graph[we[0] - 1].append([we[1] - 1, we[2]])

    dijkstra(graph, n - 1, k - 1, dist)

    print(dist)
    time = max(dist)

    if time == math.inf:
        return -1
    else:
        return time


times = [[2, 1, 1], [2, 3, 1], [3, 4, 1]]
n = 4
k = 2

print(networkDelayTime(times, n, k))
