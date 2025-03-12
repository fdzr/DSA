from typing import List

type Matrix = List[List[int]]


def is_valid(boogle: Matrix, visited: Matrix, row: int, col: int):
    return (
        row >= 0
        and row < len(boogle)
        and col >= 0
        and col < len(boogle[0])
        and visited[row][col] == 0
    )


def max_path(
    boogle: Matrix,
    visited: Matrix,
    row: int,
    col: int,
    cont: int,
    max_cont: List,
    previous_char: chr,
):
    visited[row][col] = 1
    current_char = boogle[row][col]

    if previous_char != " " and chr(ord(previous_char) + 1) != current_char:
        max_cont[0] = max(max_cont[0], cont)
        return

    if previous_char != " " and chr(ord(previous_char) + 1) == current_char:
        cont += 1

    directions = [[-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]]

    for x, y in directions:
        new_row = x + row
        new_col = y + col

        if is_valid(boogle, visited, new_row, new_col):
            max_path(
                boogle, visited, new_row, new_col, cont, max_cont, boogle[row][col]
            )
            visited[new_row][new_col] = 0


if __name__ == "__main__":
    boogle = [
        ["D", "E", "H", "X", "B"],
        ["A", "O", "G", "P", "E"],
        ["D", "D", "C", "F", "D"],
        ["E", "B", "E", "A", "S"],
        ["C", "D", "Y", "E", "N"],
    ]

    previous_char = " "
    cont = 1
    max_cont = [0]
    visited = [[0] * len(row) for row in boogle]
    max_path(boogle, visited, 2, 2, cont, max_cont, previous_char)

    print(max_cont)
