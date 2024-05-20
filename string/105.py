def findTheDifference(s: str, t: str) -> str:
    chars = [0] * 26
    for ch in s:
        chars[ord(ch) - 97] += 1

    for ch in t:
        chars[ord(ch) - 97] -= 1
        if chars[ord(ch) - 97] == -1:
            return ch


print(findTheDifference("", "y"))
