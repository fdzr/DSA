from typing import List


class TreeNode:
    def __init__(self, k: int):
        self.val: int = k
        self.left: TreeNode = None
        self.right: TreeNode = None


class DSU:
    def __init__(self, n: int):
        self.parent = [-1] * n
        self.rank = [0] * n

    def find(self, u: int):
        if self.parent[u] == -1:
            return u

        self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def merge(self, u: int, v: int):
        x: int = self.find(u)
        y: int = self.find(v)

        if x != y:
            if self.rank[x] > self.rank[y]:
                self.parent[y] = x
            elif self.rank[y] > self.rank[x]:
                self.parent[x] = y
            else:
                self.parent[y] = x
                self.rank[x] += 1


def countCompleteComponents(n: int, edges: List[List[int]]) -> int:
    dsu = DSU(n)
    vertex_set = {}
    edge_set = {u: 0 for u in range(n)}
    answer = 0
    components_processed = set()

    for u, v in edges:
        dsu.merge(u, v)

    for u, v in edges:
        u_temp = dsu.find(u)

        if u_temp not in vertex_set:
            vertex_set[u_temp] = set()

        vertex_set[u_temp].add(u)
        vertex_set[u_temp].add(v)

        edge_set[u_temp] += 1

    for u in range(n):
        v = dsu.find(u)
        if v not in vertex_set and v not in components_processed:
            answer += 1
        else:
            number_vertex = len(vertex_set[v])
            if (
                edge_set[v] == number_vertex * (number_vertex - 1) // 2
                and v not in components_processed
            ):
                answer += 1

        components_processed.add(v)

    return answer


n = 6
edges = [[0, 1], [0, 2], [1, 2], [3, 4], [3, 5]]
print(countCompleteComponents(n, edges))
