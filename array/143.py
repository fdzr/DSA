from typing import List


def maxProfit(prices: List[int]) -> int:
    initial = prices[0]
    profit = 0

    for index in range(1, len(prices)):
        if prices[index] - initial > profit:
            profit = prices[index] - initial
        elif prices[index] < initial:
            initial = prices[index]

    return profit


profit = maxProfit([11, 3, 2, 4, 10])
print(profit)
