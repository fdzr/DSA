from typing import List
from collections import deque


def is_valid(grid, visited, row, col):
    return (
        row >= 0
        and row < len(grid)
        and col >= 0
        and col < len(grid[0])
        and visited[row][col] == 0
        and grid[row][col] == 1
    )


def BFS(grid, visited, q: deque):
    time = 0

    posRows = [-1, 0, 0, 1]
    posCols = [0, -1, 1, 0]

    while len(q) != 0:
        row, col, time = q.popleft()
        visited[row][col] = 1

        for index in range(len(posRows)):
            newPosRow = row + posRows[index]
            newPosCol = col + posCols[index]

            if is_valid(grid, visited, newPosRow, newPosCol):
                grid[newPosRow][newPosCol] = 2
                q.append([newPosRow, newPosCol, time + 1])

    return time


def check_matrix(grid, check_fresh_fruit, check_rotten_fruit):
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if check_fresh_fruit is True and grid[row][col] == 1:
                return True
            if check_rotten_fruit is True and grid[row][col] == 2:
                return True

    return False


def orangesRotting(grid: List[List[int]]) -> int:
    q = deque()
    visited = [[0] * len(row) for row in grid]

    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 2:
                q.append([row, col, 0])

    if check_matrix(grid, True, False) and check_matrix(grid, False, True) is False:
        return -1
    if (
        check_matrix(grid, True, False) is False
        and check_matrix(grid, False, True) is True
    ):
        return 0

    answer = BFS(grid, visited, q)
    if check_matrix(grid, True, False):
        return -1

    return answer


grid = [[0, 2]]

print(orangesRotting(grid))
