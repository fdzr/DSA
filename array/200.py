from typing import List


def maximumCandies(candies: List[int], k: int) -> int:
    sum_candies = sum(candies)

    if sum_candies < k:
        return 0

    sol = 0
    L, R = 1, max(candies)

    while L <= R:
        count = 0
        M = L + (R - L) // 2

        for c in candies:
            count += c // M

        if count >= k:
            L = M + 1
            sol = max(sol, M)
        else:
            R = M - 1

    return sol


if __name__ == "__main__":
    candies = [5, 2]
    k = 11
    print(maximumCandies(candies, k))
