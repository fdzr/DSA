import math


def arrangeCoins(n: int) -> int:
    return int(-1 + math.sqrt(1 + 8 * n)) // 2


print(arrangeCoins(1804289383))