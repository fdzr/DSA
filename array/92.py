from typing import List
import math


def smallestEqual(nums: List[int]) -> int:
    min_ = math.inf
    for index, _ in enumerate(nums):
        rest = index % 10
        if rest == nums[index] and index < min_:
            min_ = index

    if min_ == math.inf:
        return -1
    else:
        return min_


if __name__ == "__main__":
    print(smallestEqual([1,2,3,4,5,6,7,8,9,0]))
