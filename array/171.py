from typing import List


def distributeCandies(candyType: List[int]) -> int:
    n = len(candyType)
    ans = [0] * 200001

    for candy in candyType:
        if candy >= 0:
            ans[candy] += 1
        else:
            ans[abs(candy) + 100000] += 1

    cont = 0
    for elem in ans:
        if elem > 0:
            cont += 1

    return min(cont, n // 2)


print(distributeCandies([1, 1, 2, 2, 3, 3, -100000, -9999, 999, 9000, 9000, 100000]))
