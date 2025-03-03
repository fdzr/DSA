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


def insert(intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
    inserted = False
    answer = []

    if len(intervals) == 0:
        return [newInterval]

    for item in intervals:
        if inserted is False:
            if newInterval[0] < item[0]:
                answer.append(newInterval)
                inserted = True
            elif newInterval[0] == item[0] and newInterval[1] <= item[1]:
                answer.append(newInterval)
                inserted = True

        answer.append(item)

    if inserted is False:
        answer.append(newInterval)

    return merge(answer)


intervals = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]]
newInterval = [4, 8]

print(insert(intervals, newInterval))
