from collections import deque
from typing import List


# def permutations(input):
#     perms = []
#     solution = []

#     def backtrack():
#         if len(input) == len(solution):
#             perms.append(solution[:])
#             print(perms)
#             return

#         for num in input:
#             if not num in solution:
#                 solution.append(num)
#                 backtrack()
#                 solution.pop()
#                 print(num)

#     return backtrack()


# # permutations([1, 2, 3])
# d = deque()
# d.append(1)
# print(d.popleft())
# print(d.popleft())


def reverseList(a: List[int]):
    return list(reversed([e for e in a if e % 2 == 0]))


print(reverseList([1, 2, 3, 4]))
