import collections


def checkAlmostEquivalent(word1: str, word2: str) -> bool:
    a = collections.Counter(word1)
    b = collections.Counter(word2)

    return all(item[1] <= 3 for item in (a-b).most_common()) and all(item[1] <= 3 for item in (b-a).most_common())


if __name__ == "__main__":
    print(checkAlmostEquivalent("abcdeef", "abaaacc"))
