from typing import List


def minimumOperations(nums: List[int]) -> int:
    cont = 0
    
    while sum(nums) != 0:
        print(nums)
        min_number = min(elem for elem in nums if elem != 0)
        nums = list(map(lambda x: x - min_number if x != 0 else 0, nums))
        
        cont += 1

    return cont


if __name__ == "__main__":
    print(minimumOperations([0]))
