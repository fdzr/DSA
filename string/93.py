from typing import List


def numOfPairs(nums: List[str], target: str) -> int:
    cont = 0
    for i in range(0, len(nums) - 1):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                cont += 1
            if nums[j] + nums[i] == target:
                cont += 1

    return cont


if __name__ == "__main__":
    print(numOfPairs(["123","4","12","34"], "1234"))
