from typing import List
from collections import deque


def is_valid(G, visited, row, col, oldColor):
    return (
        row >= 0
        and row < len(G)
        and col >= 0
        and col < len(G[0])
        and visited[row][col] == 0
        and G[row][col] == oldColor
    )


def BFS(G, row, col, color):
    q = deque()
    q.append([row, col])
    old_color = G[row][col]
    visited = [[0] * len(row) for row in G]

    adj = [[-1, 0], [0, -1], [0, 1], [1, 0]]

    while len(q) > 0:
        elem = q.popleft()
        visited[elem[0]][elem[1]] = 1
        G[elem[0]][elem[1]] = color

        for coordinates in adj:
            newPosRow = elem[0] + coordinates[0]
            newPosCol = elem[1] + coordinates[1]

            if is_valid(G, visited, newPosRow, newPosCol, old_color):
                q.append([newPosRow, newPosCol])


def floodFill(image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
    BFS(image, sr, sc, color)
    return image


def print_matrix(G):
    for row in G:
        for elem in row:
            print(elem, end=" ")

        print()


G = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]

print_matrix(G)
print()
print_matrix(floodFill(G, 1, 1, 2))
