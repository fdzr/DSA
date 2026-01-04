from typing import List


def maximumHappinessSum(happiness: List[int], k: int) -> int:
    happiness.sort(reverse=True)

    ans, index, decrement = 0, 0, 0

    while k > 0:
        if happiness[index] > 0:
            ans += max(happiness[index] - decrement, 0)
            decrement += 1
            index += 1
            k -= 1

    return ans


v = [2, 3, 4, 5]
k = 1
print(maximumHappinessSum(v, k))
