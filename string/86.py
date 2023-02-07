from typing import List
import collections


def countWords(words1: List[str], words2: List[str]) -> int:
    dict_word1, dict_word2 = collections.defaultdict(int), collections.defaultdict(int)
    for word in words1:
        dict_word1[word] += 1

    for word in words2:
        dict_word2[word] += 1

    count = 0
    for word, freq in dict_word1.items():
        if freq == 1 and word in dict_word2 and dict_word2[word] == 1:
            count += 1

    return count


if __name__ == "__main__":
    print(countWords(["b","bb","bbb"],["a","aa","aaa"]))
