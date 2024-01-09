from collections import defaultdict
from io import StringIO


def frequencySort(s: str) -> str:
    freq = defaultdict(int)

    for c in s:
        freq[c] += 1

    l = sorted(freq.items(), key=lambda x: x[1], reverse=True)
    ans = StringIO()

    for item in l:
        ans.write(item[0] * item[1])

    return ans.getvalue()


print(frequencySort("tree"))
