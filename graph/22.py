def is_valid(board, visited, row, col):
    return (
        row >= 0
        and row < len(board)
        and col >= 0
        and col < len(board[0])
        and visited[row][col] == 0
        and board[row][col] == 1
    )


def max_area_island(board):
    visited = [[0] * len(row) for row in board]
    cont = 0
    max_area = 0
    directions = [(0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (-1, 1)]

    def DFS(row, col, cont):
        visited[row][col] = 1
        cont[0] += 1

        for item in directions:
            newRow = row + item[0]
            newCol = col + item[1]

            if is_valid(board, visited, newRow, newCol):
                DFS(newRow, newCol, cont)

    for row in range(len(board)):
        for col in range(len(board[row])):
            if visited[row][col] == 0 and board[row][col] == 1:
                cont = [0]
                DFS(row, col, cont)
                if cont[0] > max_area:
                    max_area = cont[0]

    return max_area


board = [
    [1, 0, 0, 0, 1, 0, 0],
    [0, 1, 0, 0, 1, 1, 0],
    [1, 1, 0, 0, 0, 0, 0],
    [1, 0, 0, 1, 1, 0, 0],
    [1, 0, 0, 1, 0, 1, 1],
]

print(max_area_island(board))
