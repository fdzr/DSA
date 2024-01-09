from typing import List
from collections import defaultdict


def getSetSize(l: List[tuple[int, int]], n: int):
    cont = 0
    cant_nums_proccessed = 0

    for _, cant in l:
        cont += cant
        cant_nums_proccessed += 1

        if n - cont <= n / 2:
            break

    return cant_nums_proccessed


def minSetSize(arr: List[int]) -> int:
    freq = defaultdict(int)
    n = len(arr)

    for num in arr:
        freq[num] += 1

    l = sorted(freq.items(), key=lambda x: x[1], reverse=True)
    r = sorted(freq.items(), key=lambda x: x[1])

    sum_left = getSetSize(l, n)
    sum_right = getSetSize(r, n)

    return min(sum_left, sum_right)


arr = [3, 3, 3, 3, 5, 5, 5, 2, 2, 7]
print(minSetSize(arr))
