from typing import List


def maxProfitAssignment(
    difficulty: List[int], profit: List[int], worker: List[int]
) -> int:
    jobs_and_difficulty = sorted(zip(difficulty, profit))
    worker.sort()

    index = 0
    acc = 0
    bestProfit = 0

    for w in worker:
        while index < len(jobs_and_difficulty) and jobs_and_difficulty[index][0] <= w:
            bestProfit = max(bestProfit, jobs_and_difficulty[index][1])
            index += 1

        acc += bestProfit

    return acc


ans = maxProfitAssignment([85, 47, 57], [24, 66, 99], [40, 25, 25])
print(ans)
