from typing import List


def canPlaceFlowers(flowerbed: List[int], n: int) -> bool:
    index = 0
    while index < len(flowerbed):
        if flowerbed[index] == 1:
            index += 2
            continue
        if (
            index + 1 < len(flowerbed)
            and flowerbed[index] == 0
            and flowerbed[index + 1] == 0
        ):
            n -= 1
            index += 2
            continue
        if index + 1 >= len(flowerbed) and flowerbed[index] == 0:
            n -= 1
            index += 2
            break
        if flowerbed[index + 1] == 1:
            index += 3
            continue

    return n <= 0


print(canPlaceFlowers([0, 0, 1, 0, 0], 3))
