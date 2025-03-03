from typing import List


def merge(intervals: List[List[int]]) -> List[List[int]]:
    intervals.sort(key=lambda x: (x[0], x[1]))
    initialInterval = intervals[0]
    answer = []

    for index in range(1, len(intervals)):
        temp = intervals[index]

        if temp[0] == initialInterval[0]:
            initialInterval[1] = temp[1]
        elif temp[0] == initialInterval[1]:
            initialInterval[1] = temp[1]
        elif temp[0] < initialInterval[1]:
            if initialInterval[1] <= temp[1]:
                initialInterval[1] = temp[1]
        else:
            answer.append(initialInterval)
            initialInterval = temp

    answer.append(initialInterval)

    return answer


intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
print(merge(intervals))
