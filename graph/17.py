from typing import List


def DFS(grid, visited, row, col, cont):
    visited[row][col] = 1

    coordinates = [(-1, 0), (0, -1), (0, 1), (1, 0)]

    for coor in coordinates:
        newPosRow = row + coor[0]
        newPosCol = col + coor[1]

        if (
            newPosRow < 0
            or newPosRow >= len(grid)
            or newPosCol < 0
            or newPosCol >= len(grid[0])
        ):
            cont[0] += 1
        elif grid[newPosRow][newPosCol] == 0:
            cont[0] += 1
        elif visited[newPosRow][newPosCol] == 0:
            DFS(grid, visited, newPosRow, newPosCol, cont)


def islandPerimeter(grid: List[List[int]]) -> int:
    visited = [[0] * len(row) for row in grid]
    cont = [0]

    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if visited[row][col] == 0 and grid[row][col] == 1:
                DFS(grid, visited, row, col, cont)
                return cont[0]

    return cont[0]


grid = [[0, 1, 0, 0], [1, 1, 1, 0], [0, 1, 0, 0], [1, 1, 0, 0]]
print(islandPerimeter(grid))
