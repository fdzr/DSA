from typing import List


def findErrorNums(nums: List[int]) -> List[int]:
    freq = [0] * (len(nums) + 1)
    answer = [0, 0]

    for elem in nums:
        freq[elem] += 1

    for index in range(1, len(freq)):
        if freq[index] == 2:
            answer[0] = index
        if freq[index] == 0:
            answer[1] = index

    return answer


print(findErrorNums([1, 2, 2, 4]))
