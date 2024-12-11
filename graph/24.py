def is_valid(board, visited, row, col):
    return (
        row >= 0
        and row < len(board)
        and col >= 0
        and col < len(board[0])
        and visited[row][col] == 0
    )


def DFS(
    board,
    visited,
    row,
    col,
    temp,
    word,
    index,
):
    visited[row][col] = 1
    temp.append(board[row][col])

    if "".join(temp) == word:
        return True

    directions = [(0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1)]

    for coordinate in directions:
        new_row = row + coordinate[0]
        new_col = col + coordinate[1]

        if (
            is_valid(board, visited, new_row, new_col) is True
            and word[index] == board[new_row][new_col]
        ):
            if DFS(board, visited, new_row, new_col, temp, word, index + 1) is True:
                return True

    visited[row][col] = 0
    temp.pop()

    return False


def find_words(board, dictionary):
    answer = []
    flag = False

    for word in dictionary:

        for row in range(len(board)):
            for col in range(len(board[row])):

                visited = [[0] * len(row) for row in board]
                if board[row][col] == word[0]:
                    if DFS(board, visited, row, col, [], word, 1) is True:
                        answer.append(word)
                        flag = True
                        break

            if flag is True:
                flag = False
                break

    return answer


boggie = [["G", "I", "Z"], ["U", "E", "K"], ["Q", "S", "E"]]
dictionary = ["GEEKS", "FOR", "QUIZ", "GO"]

print(find_words(boggie, dictionary))
