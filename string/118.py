from collections import Counter


def firstUniqChar(s: str) -> int:
    freq = Counter(s)
    flag = False

    for index, ch in enumerate(s):
        if freq[ch] == 1:
            return index

    return -1


print(firstUniqChar("aabb"))
