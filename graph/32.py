from typing import List
import math

addr = [[-1, 0], [0, 1], [1, 0], [0, -1]]


def dfs(grid: List[List[int]], row: int, col: int, cont: List[int]):
    if (
        row < 0
        or row >= len(grid)
        or col < 0
        or col >= len(grid[0])
        or grid[row][col] == 0
    ):
        return

    cont[0] += grid[row][col]
    grid[row][col] = 0

    for item in addr:
        newRow = item[0] + row
        newCol = item[1] + col
        dfs(grid, newRow, newCol, cont)


def findMaxFish(grid: List[List[int]]) -> int:
    cont = [0]
    maxFish = 0
    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] > 0:
                dfs(grid, row, col, cont)
                maxFish = max(maxFish, cont[0])
                cont = [0]

    return maxFish


grid = [[0, 2, 1, 0], [4, 0, 0, 3], [1, 0, 0, 4], [0, 3, 2, 0]]
print(findMaxFish(grid))
