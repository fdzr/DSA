from typing import List

# https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/


def kLengthApart(nums: List[int], k: int) -> bool:
    saw_target = False
    cont_target = 0

    for value in nums:
        if value == 1:
            if saw_target is False:
                saw_target = True
            else:
                if cont_target < k:
                    return False

                cont_target = 0
        else:
            cont_target += 1

    return True


print(kLengthApart([1, 0, 0, 1, 0, 1, 1, 0], 2))
