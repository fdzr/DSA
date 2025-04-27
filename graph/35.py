from typing import List
from collections import deque

type Matrix = List[List[int]]


def is_valid(graph: Matrix, visited: Matrix, row: int, col: int):
    return (
        row >= 0
        and row < len(graph)
        and col >= 0
        and col < len(graph[0])
        and visited[row][col] == 0
        and graph[row][col] == 1
    )


def dfs(graph: Matrix, visited: Matrix, row: int, col: int) -> tuple[int, ...]:
    q = deque([(row, col)])
    sol: tuple[int, ...] = None

    visited[row][col] = 1

    while len(q) > 0:
        coor = q.popleft()

        for r_, c_ in [[-1, 0], [0, 1], [1, 0], [0, -1]]:
            newRow = r_ + coor[0]
            newCol = c_ + coor[1]

            if is_valid(graph, visited, newRow, newCol):
                if sol is None:
                    sol = (newRow, newCol)
                else:
                    if (newRow, newCol) > sol:
                        sol = (newRow, newCol)
                visited[newRow][newCol] = 1
                q.append((newRow, newCol))

    return sol


def findFarmland(land: Matrix) -> Matrix:
    visited: Matrix = [[0] * len(row) for row in land]
    solution: Matrix = []

    for row in range(len(land)):
        for col in range(len(land[row])):
            if land[row][col] == 1 and visited[row][col] == 0:
                sol = dfs(land, visited, row, col)
                item = [row, col]
                if sol == None:
                    item.append(row)
                    item.append(col)
                else:
                    item.append(sol[0])
                    item.append(sol[1])

                solution.append(item)

    return solution


if __name__ == "__main__":
    land = [[0]]
    sol = findFarmland(land)
    print(sol)
