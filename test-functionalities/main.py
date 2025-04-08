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


class test:
    id = 0

    def __init__(self, id):
        self.id = id
        id = 2


t = test(1)
print(t.id)

a: float = 1


a = 7
print(a.__str__())

import re

m = re.search(r"(ab[cd]?)", "acdeabdabcde")
print(m.groups())


import itertools

print()
print(list(itertools.islice(itertools.count(5), 10)))


text = "abc123def456ghi"
patter = r"(?:abc)\d+"
matches = re.findall(patter, text)
print(matches)
