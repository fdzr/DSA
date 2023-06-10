from typing import List


def removeDuplicates(nums: List[int]) -> int:
    non_repeated = {}
    for elem in nums:
        non_repeated[elem] = 0

    answer = len(non_repeated.keys())
    for index, elem in zip(range(0, answer), non_repeated.keys()):
        nums[index] = elem

    return answer


if __name__ == "__main__":
    print(removeDuplicates([0]))
