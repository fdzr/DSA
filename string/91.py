from typing import List


def aux(word1: str, word2: str):
    l = 26 * [0]
    r = 26 * [0]

    for ch in word1:
        l[ord(ch) - 97] = 1

    for ch in word2:
        r[ord(ch) - 97] = 1

    return l == r


def similarPairs(words: List[str]) -> int:
    cont = 0
    for i in range(len(words) - 1):
        for j in range(i + 1, len(words)):
            cont += aux(words[i], words[j])

    return cont


if __name__ == "__main__":
    print(similarPairs(["aabb","ab","ba"]))