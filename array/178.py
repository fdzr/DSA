from typing import List


def distributeCandies(candies: int, num_people: int) -> List[int]:
    people = [0] * num_people
    iteration = 0

    while candies > 0:

        for index in range(num_people):
            if candies <= 0:
                break

            people[index] += min(num_people * iteration + index + 1, candies)
            candies -= num_people * iteration + index + 1

        iteration += 1

    return people


print(distributeCandies(10, 3))
