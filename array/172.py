from typing import List


def findShortestSubArray(nums: List[int]) -> int:
    ans = {}
    distance = 2**31 - 1
    cont = 0

    for index, value in enumerate(nums):
        if not value in ans:
            ans[value] = [index, index, 1]
        else:
            ans[value][2] += 1
            ans[value][0] = index

        if ans[value][2] > cont:
            distance = ans[value][0] - ans[value][1]
            cont = ans[value][2]
        elif ans[value][2] == cont:
            diff = ans[value][0] - ans[value][1]
            if diff < distance:
                distance = diff

    return distance + 1


print(findShortestSubArray([1, 2, 2, 3, 1]))
