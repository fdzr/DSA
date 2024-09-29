from typing import List


def findContentChildren(g: List[int], s: List[int]) -> int:
    g.sort(reverse=True)
    s.sort(reverse=True)
    indexSize, output = 0, 0

    for _, value in enumerate(g):
        if indexSize >= len(s):
            break
        if s[indexSize] >= value:
            output += 1
            indexSize += 1

    return output


print(findContentChildren([1, 2, 3], [1, 1]))
