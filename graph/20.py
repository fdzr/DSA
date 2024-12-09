from typing import List


def DFS(board: List[List], visited: List[List], row: int, col: int):
    visited[row][col] = 1
    directions = [(0, -1), (-1, 0), (0, 1), (1, 0)]

    for coor in directions:
        newRow = row + coor[0]
        newCol = col + coor[1]

        if is_valid(board, visited, newRow, newCol):
            DFS(board, visited, newRow, newCol)


def countBattleships(board: List[List[str]]) -> int:
    visited = [[0] * len(item) for item in board]
    battleship = 0

    for row in range(0, len(board)):
        for col in range(len(board[row])):
            if visited[row][col] == 0 and board[row][col] == "X":
                battleship += 1
                DFS(board, visited, row, col)

    return battleship


board = [["X", ".", ".", "X"], [".", ".", ".", "X"], [".", ".", ".", "X"]]
print(countBattleships(board))
board = [["."]]
print(countBattleships(board))
