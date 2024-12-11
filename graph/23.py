from typing import List
from collections import deque


def shortestDistanceAfterQueries(n: int, queries: List[List[int]]) -> List[int]:
    graph = [[index + 1] for index in range(0, n - 1)]
    graph.append([])
    outputs = []

    def bfs():
        visited = [0] * len(graph)
        q = deque()
        q.append((0, 0))

        while q:
            item = q.popleft()
            visited[item[0]] = 1

            if item[0] == len(graph) - 1:
                return item[1]

            for v in graph[item[0]]:
                if visited[v] == 0:
                    q.append((v, item[1] + 1))

    for q in queries:
        graph[q[0]].append(q[1])
        outputs.append(bfs())

    return outputs


n = 5
queries = [[2, 4], [0, 2], [0, 4]]
print(shortestDistanceAfterQueries(n, queries))
print()
queries = [[0, 3], [0, 2]]
n = 4
print(shortestDistanceAfterQueries(n, queries))
