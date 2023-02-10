from typing import List


def minMovesToSeat(seats: List[int], students: List[int]) -> int:
    count = 0
    seats.sort()
    students.sort()
    for item in zip(seats, students):
        count += abs(item[0] - item[1])

    return count


if __name__ == "__main__":
    print(minMovesToSeat([2,2,6,6],[1,3,2,6]))
