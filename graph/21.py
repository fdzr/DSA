from collections import deque


def is_valid(board, visited, row, col):
    return (
        row >= 0
        and row < len(board)
        and col >= 0
        and col < len(board[0])
        and visited[row][col] == 0
    )


def belongs_to_component(board, row, col, color):
    return board[row][col] == color


def is_border(board, row, col):
    return row == 0 or row == len(board) - 1 or col == 0 or col == len(board[0]) - 1


def color_border(board, row, col, color):
    visited = [[0] * len(item) for item in board]
    color_starting_point = board[row][col]

    q = deque()
    q.append([row, col])

    coordinates = [(0, -1), (-1, 0), (0, 1), (1, 0)]

    while q:
        coor = q.popleft()
        visited[coor[0]][coor[1]] = 1

        if is_border(board, coor[0], coor[1]):
            board[coor[0]][coor[1]] = color

        for item in coordinates:
            newRow = coor[0] + item[0]
            newCol = coor[1] + item[1]

            if is_valid(board, visited, newRow, newCol):
                if belongs_to_component(board, newRow, newCol, color_starting_point):
                    q.append([newRow, newCol])
                else:
                    board[coor[0]][coor[1]] = color

    return board


def print_matrix(board):
    for row in range(len(board)):
        for col in range(len(board[row])):
            print(board[row][col], end=" ")

        print()

    print()


board = [[1, 1], [1, 2]]
row, col = 0, 0
color = 3

print_matrix(color_border(board, row, col, color))


board = [[1, 2, 2], [2, 3, 2]]
row = 0
col = 1
color = 3
print_matrix(color_border(board, row, col, color))


board = [[1, 1, 1], [1, 1, 4], [1, 1, 1]]
row = 1
col = 1
color = 2
print_matrix(color_border(board, row, col, color))
