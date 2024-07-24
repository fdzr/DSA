def wordPattern(pattern: str, s: str) -> bool:
    mapping_1, mapping_2 = {}, {}
    words = s.strip().split()

    if len(pattern) != len(words):
        return False

    for idx, c in enumerate(pattern):
        condition_1 = c in mapping_1 and mapping_1[c] != words[idx]
        condition_2 = words[idx] in mapping_2 and mapping_2[words[idx]] != c
        if condition_1 or condition_2:
            return False
        else:
            mapping_1[c] = words[idx]
            mapping_2[words[idx]] = c

    return True


print(wordPattern("abba", "dog cat cat fish"))
