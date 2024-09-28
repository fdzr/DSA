from typing import List


def countStudents(students: List[int], sandwiches: List[int]) -> int:
    number_no_match = 0
    index_sandwich = 0

    while True:
        if students[0] == sandwiches[index_sandwich]:
            index_sandwich += 1
            students.pop(0)
            number_no_match = 0
        else:
            number_no_match += 1
            temp = students.pop(0)
            students.append(temp)

        if number_no_match == len(students) or len(students) == 0:
            break

    return len(students)


print(countStudents([1, 1, 1, 0, 0, 1], [1, 0, 0, 0, 1, 1]))
