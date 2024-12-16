from typing import List


def create_combinations(open, close, res, answer, n):
    if len(res) == n * 2:
        answer.append("".join(res))

    if open < n:
        res.append("(")
        create_combinations(
            open + 1,
            close,
            res,
            answer,
            n,
        )
        res.pop()

    if close < open:
        res.append(")")
        create_combinations(
            open,
            close + 1,
            res,
            answer,
            n,
        )
        res.pop()


def generateParenthesis(n: int) -> List[str]:
    res = []
    answer = []

    create_combinations(0, 0, res, answer, n)

    return answer


n = 3
for item in generateParenthesis(n):
    print(item)
