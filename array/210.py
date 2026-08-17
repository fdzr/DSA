from typing import List

# def stoneGame(piles: List[int]) -> bool:
#     # start, end = 0, len(piles) - 1
#     # Alice = 0
#     # Bob = 0
#     # flag = False

#     # while start != end:
#     #     if piles[start] == piles[end]:
#     #         if end - start > 1:
#     #             if piles[start + 1] == piles[end - 1]:
#     #                 if flag is False:
#     #                     Alice += piles[start]
#     #                 else:
#     #                     Bob += piles[start]

#     #                 start += 1
#     #                 continue

#     #             elif piles[start + 1] < piles[end - 1]:
#     #                 if flag is False:
#     #                     Alice += piles[end]
#     #                 else:
#     #                     Bob += piles[end]

#     #                 end -= 1
#     #             else:
#     #                 if flag is False:
#     #                     Alice += piles[start]
#     #                 else:
#     #                     Bob += piles[start]

#     #                 start += 1

#     #         else:
#     #             if flag is False:
#     #                 Alice += piles[start]
#     #             else:
#     #                 Bob += piles[start]

#     #         continue

#     #     if piles[start] > piles[end]:
#     #         if flag is False:
#     #             Alice += piles[start]
#     #         else:
#     #             Bob += piles[start]

#     #         start += 1

#     #     else:
#     #         if flag is False:
#     #             Alice += piles[end]
#     #         else:
#     #             Bob += piles[end]

#     #         end -= 1

#     #     flag = not flag

#     # if flag is False:
#     #     Alice += piles[start]
#     # else:
#     #     Bob += piles[end]

#     # return Alice > Bob


def stoneGame(piles: List[int]):
    pass


print(stoneGame([3, 2, 10, 4]))
