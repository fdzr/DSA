from typing import List


def dfs(
    board: List[List],
    visited: List,
    source: int,
    dest: int,
    k: int,
    time: int,
    cont: List,
):
    if time == k and source == dest:
        cont[0] += 1
        return

    visited[source] = 1

    for v, i in enumerate(board[source]):
        if visited[v] == 0 and i == 1:
            dfs(board, visited, v, dest, k, time + 1, cont)

    visited[source] = 0


def get_possible_walks(board: List[List], source: int, dest: int, k: int):
    visited = [0] * len(board)
    cont, time = [0], 0

    dfs(board, visited, source, dest, k, time, cont)

    return cont[0]


board = [[0, 1, 1, 1], [0, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 0]]
source, dest, k = 0, 3, 2

print(get_possible_walks(board, source, dest, k))
