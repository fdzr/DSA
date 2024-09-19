from typing import List


def get_preffix(string_a: str, string_b: str):
    index = 0
    while (
        index < len(string_a)
        and index < len(string_b)
        and string_a[index] == string_b[index]
    ):
        index += 1

    return string_a[:index]


def longestCommonPrefix(strs: List[str]) -> str:
    preffix = strs[0]
    index = 1

    while index < len(strs):
        preffix = get_preffix(preffix, strs[index])
        index += 1

    return preffix

    # for index_i in range(0, len(strs) - 1):
    #     for index_j in range(index_i + 1, len(strs)):
    #         tmp = get_preffix(strs[index_i], strs[index_j])
    #         print(tmp)

    # return None


answer = longestCommonPrefix(["dog", "racecar", "car"])
print(answer)
