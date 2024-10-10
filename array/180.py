from typing import List
import copy


def findRelativeRanks(score: List[int]) -> List[str]:
    ans = []
    score_aux = copy.deepcopy(score)
    score_aux.sort(reverse=True)
    um = {}

    for index, elem in enumerate(score_aux):
        if index == 0:
            um[elem] = "Gold Medal"
        elif index == 1:
            um[elem] = "Silver Medal"
        elif index == 2:
            um[elem] = "Bronze Medal"
        else:
            um[elem] = str(index + 1)

    for elem in score:
        ans.append(um[elem])

    return ans


print(findRelativeRanks([10, 3, 8, 9, 4]))
