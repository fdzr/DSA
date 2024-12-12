def dfs(s, start, max_quantity, unique_subs):
    if start >= len(s):
        max_quantity[0] = max(max_quantity[0], len(unique_subs))
        return

    for i in range(start, len(s)):
        chunk = s[start : i + 1]

        if chunk in unique_subs:
            continue

        unique_subs.add(chunk)
        dfs(s, i + 1, max_quantity, unique_subs)
        unique_subs.remove(chunk)


def maxUniqueSplit(s: str) -> int:
    unique_subs = set()
    max_quantity = [0]

    dfs(s, 0, max_quantity, unique_subs)

    return max_quantity[0]


s = "a"
print(maxUniqueSplit(s))
