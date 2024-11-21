from typing import List


def is_valid(grid, visited, row, col):
    return (
        row >= 0
        and row < len(grid)
        and col >= 0
        and col < len(grid[0])
        and visited[row][col] == 0
        and grid[row][col] == 1
    )


def DFS(grid, visited, row, col, cont):
    coordinates = [(-1, 0), (0, -1), (0, 1), (1, 0)]

    visited[row][col] = 1

    for coor in coordinates:
        newPosRow = row + coor[0]
        newPosCol = col + coor[1]

        if is_valid(grid, visited, newPosRow, newPosCol):
            cont[0] += 1
            DFS(grid, visited, newPosRow, newPosCol, cont)


def maxAreaOfIsland(grid: List[List[int]]) -> int:
    max_area = 0

    visited = [[0] * len(row) for row in grid]

    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1 and visited[row][col] == 0:
                cont = [1]
                DFS(grid, visited, row, col, cont)

                if cont[0] > max_area:
                    max_area = cont[0]
                    cont = [0]

    return max_area


# grid = [
#     [0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
#     [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
#     [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
#     [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
#     [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
#     [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
#     [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
#     [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
# ]

grid = [[0, 0, 0, 0, 0, 0, 0, 0]]

print(maxAreaOfIsland(grid))
