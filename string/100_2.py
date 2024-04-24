from typing import List


def addSpaces(s: str, spaces: List[int]) -> str:
    sol = []
    i = 0

    for idx in spaces:
        sol.append(s[i:idx])
        i = idx

    sol.append(s[i:])
    return " ".join(sol)


if __name__ == "__main__":
    s = "spacing"
    spaces = [0, 1, 2, 3, 4, 5, 6]
    print(addSpaces(s, spaces))
