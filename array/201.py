from typing import List


def merge_intervals(meetings: List[List[int]]):
    meetings.sort(key=lambda x: (x[0], x[1]))

    answer = []

    initialInterval = meetings[0]

    for index in range(1, len(meetings)):
        temp = meetings[index]

        if temp[0] <= initialInterval[1] or temp[0] - initialInterval[1] == 1:
            if temp[1] >= initialInterval[1]:
                initialInterval[1] = temp[1]
        else:
            answer.append(initialInterval)
            initialInterval = temp

    answer.append(initialInterval)

    return answer


def countDays(days: int, meetings: List[List[int]]) -> int:
    schedule = merge_intervals(meetings)

    initial = schedule[0]

    cont = initial[0] - 1

    for index in range(1, len(schedule)):
        cont += schedule[index][0] - initial[1] - 1
        initial = schedule[index]

    cont += days - schedule[len(schedule) - 1][1]

    return cont


if __name__ == "__main__":
    meetings = [
        [3, 49],
        [23, 44],
        [21, 56],
        [26, 55],
        [23, 52],
        [2, 9],
        [1, 48],
        [3, 31],
    ]
    days = 57

    print(countDays(days, meetings))
