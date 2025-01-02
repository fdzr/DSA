import heapq
from typing import List
import math


class Edge:
    def __init__(self, w: int, weight: int, time: int):
        self.w = w
        self.weight = weight
        self.time = time

    def __lt__(self, other):
        return self.weight > other.weight


def dijkstra(
    graph: List[List[Edge]],
    source: int,
    dest: int,
    stops: int,
    dist: List,
    is_answer: List,
):
    heap = []
    dist[source] = 0
    heapq.heappush(heap, Edge(source, 0, 0))

    while len(heap) > 0:
        edge = heapq.heappop(heap)

        if edge.w == dest:
            is_answer[0] = True
            return

        for v in graph[edge.w]:
            if dist[v.w] > dist[edge.w] + v.weight and edge.time <= stops:
                dist[v.w] = dist[edge.w] + v.weight
                heapq.heappush(heap, Edge(v.w, dist[v.w], edge.time + 1))

    return -1


def findCheapestPrice(
    n: int, flights: List[List[int]], src: int, dst: int, k: int
) -> int:
    dist = [math.inf] * n
    graph = [[] for _ in range(n)]
    is_answer = [False]

    for f in flights:
        graph[f[0]].append(Edge(f[1], f[2], 0))

    dijkstra(graph, src, dst, k, dist, is_answer)

    if is_answer[0] is True:
        return dist[dst]

    return -1


flights = [
    [0, 1, 100],
    [0, 2, 100],
    [2, 3, 1],
    [1, 4, 602],
    [3, 4, 600],
    [4, 5, 6],
    [5, 6, 6],
]
n = 7
src = 0
dst = 6
k = 3

print(findCheapestPrice(n, flights, src, dst, k))
