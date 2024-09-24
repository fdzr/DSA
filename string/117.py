from typing import List


def isPrefixString(s: str, words: List[str]) -> bool:
    pos = 0

    for index in range(len(words)):
        found = s.find(words[index], pos)
        if found == -1 or found != pos:
            return False

        pos += len(words[index])
        if pos >= len(s):
            return True

    if pos < len(s):
        return False

    return True


print(isPrefixString("cccccccc", ["c", "cc"]))
