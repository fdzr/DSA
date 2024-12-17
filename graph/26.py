from typing import List
from collections import deque


def topological_sort(graph: List[List], in_degree: List):
    q = deque()

    for u, value in enumerate(in_degree):
        if value == 0:
            q.append(u)

    while len(q) > 0:
        v = q.popleft()

        for u in graph[v]:
            in_degree[u] -= 1

            if in_degree[u] == 0:
                q.append(u)

    return sum(in_degree) == 0


def create_adj_matrix(graph: List[List], source: int, dest: int):
    graph[source].append(dest)


def canFinish(numCourses: int, prerequisites: List[List[int]]) -> bool:
    graph = [[] for _ in range(numCourses)]
    in_degree = [0 for _ in range(numCourses)]

    for item in prerequisites:
        create_adj_matrix(
            graph,
            item[1],
            item[0],
        )
        in_degree[item[0]] += 1

    return topological_sort(graph, in_degree)


numCourses = 5
prerequisites = [[1, 4], [2, 4], [3, 1], [3, 2]]
print(canFinish(numCourses, prerequisites))
