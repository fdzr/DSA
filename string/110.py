from typing import List


def shortestToChar(s: str, c: str) -> List[int]:
    indexes = [idx for idx, ch in enumerate(s) if ch == c]
    ans = [0] * len(s)
    slow_index, fast_index = 0, None if len(indexes) == 1 else 1

    for idx, ch in enumerate(s):
        if fast_index is not None:
            if idx > indexes[fast_index]:
                slow_index += 1
                if slow_index < len(indexes) - 1:
                    fast_index = slow_index + 1
                else:
                    fast_index = None
            if fast_index is not None:
                ans[idx] = min(
                    abs(idx - indexes[slow_index]), abs(idx - indexes[fast_index])
                )
            else:
                ans[idx] = abs(idx - indexes[slow_index])
        else:
            ans[idx] = abs(idx - indexes[slow_index])

    return ans


print(shortestToChar("abba", "b"))
