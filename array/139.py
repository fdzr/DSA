from typing import List


def fillCups(amount: List[int]) -> int:
    amount.sort()
    cant = 0

    while any(amount):
        if amount[0] > 0 and amount[2] > 0:
            amount[0] -= 1
            amount[2] -= 1
            amount.sort()
            cant += 1
            continue
        if amount[1] > 0 or amount[2] > 0:
            cant += max(amount[1], amount[2])
            break

    return cant


print(fillCups([2, 4, 2]))
