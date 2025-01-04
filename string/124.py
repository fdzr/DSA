from typing import List


def wordBreak(s: str, wordDict: List[str]) -> bool:
    dp = [False] * (len(s) + 1)
    dp[0] = True
    n = len(s)
    word_set = set(wordDict)

    for i in range(1, n + 1):
        for j in range(i):
            substr = s[j:i]
            if dp[j] is True and substr in word_set:
                dp[i] = True
                break

    return dp[n]


s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
print(wordBreak(s, wordDict))
