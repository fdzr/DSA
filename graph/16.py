from typing import List


def is_edge(G, row, col):
    return row == 0 or row == len(G) - 1 or col == 0 or col == len(G[0]) - 1


def is_valid(G, row, col):
    return (
        row >= 0
        and row < len(G)
        and col >= 0
        and col < len(G[0]) - 1
        and G[row][col] == "O"
    )


def DFS(G, row, col):
    posRows = [-1, 0, 0, 1]
    posCols = [0, -1, 1, 0]

    G[row][col] = "#"

    for index in range(len(posRows)):
        newPosRow = row + posRows[index]
        newPosCol = col + posCols[index]

        if (
            is_valid(G, newPosRow, newPosCol)
            and is_edge(G, newPosRow, newPosCol) is False
        ):
            DFS(G, newPosRow, newPosCol)


def solve(board: List[List[str]]) -> None:
    for row in range(len(board)):
        if board[row][0] == "O":
            DFS(board, row, 0)

        if board[row][len(board[0]) - 1] == "O":
            DFS(board, row, len(board[0]) - 1)

    for col in range(len(board[0])):
        if board[0][col] == "O":
            DFS(board, 0, col)
        if board[len(board) - 1][col] == "O":
            DFS(board, len(board) - 1, col)

    for row in range(len(board)):
        for col in range(len(board[row])):
            if board[row][col] == "O":
                board[row][col] = "X"
            if board[row][col] == "#":
                board[row][col] = "O"


def print_matrix(G):
    for row in range(len(G)):
        for col in range(len(G[row])):
            print(G[row][col], end=" ")

        print()


G = [
    ["X", "X", "X", "X"],
    ["X", "O", "O", "O"],
    ["X", "X", "O", "X"],
    ["X", "O", "X", "X"],
]


print_matrix(G)
print()
solve(G)
print_matrix(G)
