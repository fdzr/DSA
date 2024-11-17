from typing import List


def is_valid(grid, visited, row, col):
    return (
        row >= 0
        and row < len(grid)
        and col >= 0
        and col < len(grid[0])
        and visited[row][col] == 0
        and grid[row][col] == "1"
    )


def DFS(grid, visited, row, col):
    visited[row][col] = 1

    posRow = [-1, 0, 0, 1]
    posCol = [0, -1, 1, 0]

    for index in range(len(posRow)):
        newPosRow = row + posRow[index]
        newPosCol = col + posCol[index]

        if is_valid(grid, visited, newPosRow, newPosCol):
            DFS(grid, visited, newPosRow, newPosCol)


def numIslands(grid: List[List[str]]) -> int:
    visited = [[0] * len(row) for row in grid]
    cont = 0

    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if visited[row][col] == 0 and grid[row][col] == "1":
                cont += 1
                DFS(grid, visited, row, col)

    return cont


grid = [
    ["1", "1", "0", "0", "0"],
    ["1", "1", "0", "0", "0"],
    ["0", "0", "1", "0", "0"],
    ["0", "0", "0", "1", "1"],
]

print(numIslands(grid))
