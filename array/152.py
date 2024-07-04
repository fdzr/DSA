from typing import List


def check_winner(board: List[List[int]]):
    cont_row = 0
    cont_col = 0
    for row in range(3):
        for col in range(3):
            cont_row += board[row][col]
            cont_col += board[col][row]

        if cont_row == 3 or cont_col == 3:
            return "A"

        if cont_col == -3 or cont_row == -3:
            return "B"

        cont_row = 0
        cont_col = 0

    sum_diag_main = sum([board[pos][pos] for pos in range(3)])
    sum_diag_no_main = sum([board[pos][3 - pos - 1] for pos in range(3)])

    if sum_diag_main == 3:
        return "A"
    if sum_diag_main == -3:
        return "B"

    if sum_diag_no_main == 3:
        return "A"
    if sum_diag_no_main == -3:
        return "B"

    return None


def tictactoe(moves: List[List[int]]) -> str:
    board = [[0, 0, 0] for row in range(3)]
    cant_mov = len(moves)

    for index, move in enumerate(moves, start=1):
        board[move[0]][move[1]] = 1 if index % 2 == 1 else -1

    winner = check_winner(board)

    if winner is None:
        return "Draw" if cant_mov == 9 else "Pending"
    else:
        return winner



print(tictactoe([[2,2],[0,2],[1,0],[0,1],[2,0],[0,0]]))
