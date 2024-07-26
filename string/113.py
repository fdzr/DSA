from collections import Counter


def lastNonEmptyString(s: str) -> str:
    freq = Counter(reversed(s))
    max_values = max(freq.values())

    return "".join([ch for ch in reversed(freq) if freq[ch] == max_values])


print(lastNonEmptyString("abcd"))
