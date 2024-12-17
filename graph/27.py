from typing import List
from collections import deque


def topological_sort(graph: List[List], in_degree: List, order: List):
    q = deque()
    for index, value in enumerate(in_degree):
        if value == 0:
            q.append(index)

    while len(q) > 0:
        v = q.popleft()
        order.append(v)

        for u in graph[v]:
            in_degree[u] -= 1

            if in_degree[u] == 0:
                q.append(u)

    return sum(in_degree) == 0


def create_adj_matrix(graph: List[List], source: int, dest: int):
    graph[source].append(dest)


def findOrder(numCourses: int, prerequisites: List[List[int]]) -> List[int]:
    graph = [[] for _ in range(numCourses)]
    in_degree = [0 for _ in range(numCourses)]
    order = []

    for item in prerequisites:
        create_adj_matrix(graph, item[1], item[0])
        in_degree[item[0]] += 1

    if topological_sort(graph, in_degree, order) is True:
        return order

    return []


numCourses = 2
prerequisites = [[1, 0]]
print(findOrder(numCourses, prerequisites))
