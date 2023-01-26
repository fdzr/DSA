from typing import List
from collections import defaultdict


def kthDistinct(arr: List[str], k: int) -> str:
    freq = defaultdict(int)
    for cad in arr:
        freq[cad] += 1

    for cad in arr:
        if freq[cad] == 1:
            k -= 1

        if k == 0:
            return cad

    return ""


if __name__ == "__main__":
    print(kthDistinct(["a"], 2))
