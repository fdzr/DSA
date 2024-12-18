from typing import List


def dfs(graph: List[List], source: int, COLOR: int, colors: List):
    colors[source] = COLOR

    for v in graph[source]:
        if colors[v] == 0:
            if dfs(graph, v, -COLOR, colors) is False:
                return False
        elif colors[v] == COLOR:
            return False

    return True


def isBipartite(graph: List[List[int]]) -> bool:
    colors = [0] * len(graph)
    COLOR = 1

    for v in range(len(graph)):
        if colors[v] == 0 and dfs(graph, v, COLOR, colors) is False:
            return False

    return True


graph = [[1, 3], [0, 2], [1, 3], [0, 2]]
print(isBipartite(graph))
