from typing import List


def minProcessingTime(processorTime: List[int], tasks: List[int]) -> int:
    min_time = float("-inf")
    index = 0
    processorTime.sort()
    tasks.sort(reverse=True)

    for elem in processorTime:
        min_time = max(elem + tasks[index], min_time)
        index += 4

    return min_time


answer = minProcessingTime([8, 10], [2, 2, 3, 1, 8, 7, 4, 5])
print(answer)
